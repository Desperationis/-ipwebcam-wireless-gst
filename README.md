# ipwebcam-wireless-gst
Simple shell script for using IP Webcam as a low-latency wireless video source with gstreamer. Ripped off from bluezio's [ipwebcam-gst](https://github.com/bluezio/ipwebcam-gst) that emulates the app as a virtual camera. I could not find reliable software that could ensure crisp, low-latency video with no compromises from a network source, so this script's purpose is to use gstreamer's built in `autovideosink` without any audio. 

## Running
`bash run.bash {IP} {port}` in raw text without quotes. 
