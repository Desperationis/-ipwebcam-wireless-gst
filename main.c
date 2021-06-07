#include <gst/gst.h>
#include "gst/gstpad.h"
#include "gst/gstutils.h"
#include "stdbool.h"
#include "stdio.h"

static void p_added(GstElement* element, GstPad* pad, gpointer user_data) {
	/* Link decodebin to autovideosink when dynamic pad is created. */
	GstElement* sink = user_data;
	gst_element_link(element, sink);
	g_printerr("Linked decodebin to autovideosink.\n");
}

int main (int argc, char *argv[])
{
	GstElement *pipeline, *source, *filter, *sink;
	GstBus *bus;
	GstMessage *msg;
	GstStateChangeReturn ret;

	/* Initialize GStreamer */
	gst_init (&argc, &argv);

	/* Create the elements */
	source = gst_element_factory_make ("souphttpsrc", "source");
	sink = gst_element_factory_make ("autovideosink", "sink");
	filter = gst_element_factory_make ("decodebin", "filter");

	/* Create the empty pipeline */
	pipeline = gst_pipeline_new ("pipeline");

	if (!pipeline || !source || !sink || !filter) {
		g_printerr ("Error: Not all elements could be created.\n");
		return -1;
	}

	/* Build the pipeline */
	gst_bin_add_many (GST_BIN (pipeline), source, filter, sink, NULL);
	if (gst_element_link(source, filter) != TRUE) {
		g_printerr ("Erorr: Elements could not be linked.\n");
		gst_object_unref (pipeline);
		return -1;
	}

	/* Modify the source's properties */
	char buffer[50];
	sprintf(buffer, "http://%s:%s/video", argv[1], argv[2]); // http link to video
	g_object_set(source, "location", buffer, NULL);
	g_object_set(sink, "sync", false, NULL);

	/* Listen for dynamic src pad */
	g_signal_connect(filter, "pad-added", G_CALLBACK(p_added), sink);

	/* Start playing */
	ret = gst_element_set_state (pipeline, GST_STATE_PLAYING);
	if (ret == GST_STATE_CHANGE_FAILURE) {
		g_printerr ("Unable to set the pipeline to the playing state.\n");
		gst_object_unref (pipeline);
		return -1;
	}

	/* Wait until error or EOS */
	bus = gst_element_get_bus (pipeline);
	msg =
	    gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
	    GST_MESSAGE_ERROR | GST_MESSAGE_EOS);


	/* Parse pipeline message */
	if (msg != NULL) {
		GError *err;
		gchar *debug_info;

		switch (GST_MESSAGE_TYPE (msg)) {
			case GST_MESSAGE_ERROR:
				gst_message_parse_error (msg, &err, &debug_info);
				g_printerr ("Error received from element %s: %s\n",
				GST_OBJECT_NAME (msg->src), err->message);
				g_printerr ("Debugging information: %s\n",
					debug_info ? debug_info : "none");
				g_clear_error (&err);
				g_free (debug_info);
				break;

			case GST_MESSAGE_EOS:
				g_print ("End-Of-Stream reached.\n");
				break;

			default:
			/* We should not reach here because we only asked for ERRORs and EOS */
			g_printerr ("Unexpected message received.\n");
			break;
		}
		gst_message_unref (msg);
	}

	/* Free resources */
	gst_object_unref (bus);
	gst_element_set_state (pipeline, GST_STATE_NULL);
	gst_object_unref (pipeline);
	return 0;
}

