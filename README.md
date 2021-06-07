# ipwebcam-wireless-gst
This is a simple gstreamer program for viewing [IP Webcam](https://play.google.com/store/apps/details?id=com.pas.webcam&hl=en_US&gl=US), an Android App, as a low-latency wireless video source with gstreamer. No audio.

## Running
To run, simply call `gst-ipwebcam {ip} {port}`, where the IP and Port are the IP and Port IP Webcam is streaming to.

## Compiling
To compile, all you need is to call this command: `sudo apt-get install cmake gcc gstreamer1.0* libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev`. After installing those packages, run `compile.bash` and the executable will be in `build/`.
