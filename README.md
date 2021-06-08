# ipwebcam-wireless-gst
This is a simple gstreamer program for viewing [IP Webcam](https://play.google.com/store/apps/details?id=com.pas.webcam&hl=en_US&gl=US), an Android App, as a low-latency wireless video source with gstreamer. No audio.

## Running
To run, install gstreamer via `sudo apt-get install gstreamer1.0*`, then run `gst-ipwebcam {ip} {port}`, where the IP and Port are the IP and Port IP Webcam is streaming to.

## Compiling (Linux)
To compile, all you need is to call this command: `sudo apt-get install cmake gcc gstreamer1.0* libgstreamer1.0-dev pkg-config libgstreamer-plugins-base1.0-dev`. After installing those packages, run `compile.bash` and the executable will be in `build/`.

## Compiling (Windows)
While you can compile this project on Windows, it is pretty janky and not recommended. Here are two ways of doing so:

1. Install pkg-config into CMake (somehow) and have it be able to find GStreamer
