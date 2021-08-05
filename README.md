# ipwebcam-wireless-gst
This is a simple gstreamer program for viewing [IP Webcam](https://play.google.com/store/apps/details?id=com.pas.webcam&hl=en_US&gl=US), an Android App, as a low-latency wireless video source with gstreamer. No audio.

## Simple option (Linux)
You can simply run `command.bash {ip} {port}` to run this program without compilation. I can't guarantee if is as efficient as compiling it however. 

## Running (Linux)
To run, install gstreamer via `sudo apt-get install gstreamer1.0*`, then run `gst-ipwebcam {ip} {port}`, where the IP and Port are the IP and Port IP Webcam is streaming to.

## Compiling (Linux)
To compile, all you need is to call this command: `sudo apt-get install cmake gcc gstreamer1.0* libgstreamer1.0-dev pkg-config libgstreamer-plugins-base1.0-dev`. After installing those packages, run `compile.bash` and the executable will be in `build/`.

## Compiling (Windows)
While you can compile this project on Windows, it is pretty janky and not recommended. Here are two ways of doing so:

1. Install pkg-config into CMake (somehow) and have it be able to find GStreamer (somehow) to be able to make a Visual Studio file with no issues in CMake. Doing this is not well documented for Windows at all.
2. Manually include include and library directories in either CMake or Visual Studio. This is easier in Visual Studio because `.props` files are included with the gstreamer installation, meaning it automatically configures those directories for you.


## Running (Windows)
In Windows, running is a bit more complicated depending on how you compiled this project. The application will run 100% fine if it is inside `C:gstreamer/.../bin/` with the runtime version, but it will not work anywhere else. To fix this, you'll have to somehow have the application look for dll's there at runtime. 
