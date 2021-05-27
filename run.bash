gst-launch-1.0 souphttpsrc location="http://${1}:${2}/video" ! queue ! decodebin ! videoconvert ! autovideosink sync=false
