gst-launch-1.0 souphttpsrc location="http://${1}:${2}/video" ! decodebin ! autovideosink sync=false
