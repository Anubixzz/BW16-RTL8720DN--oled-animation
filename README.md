# **BW16 OLED Animation Player**

### A simple frame-by-frame animation player for the BW16 (RTL8720DN) using a 128×64 SSD1306 OLED display.
***
## **About**

This is my first embedded development project.

The original goal wasn't to build a complete animation framework or media player. I simply wanted to display the lyrics of a song that I really like on the BW16's OLED display, similar to projects I had seen for the ESP32.
Since I couldn't find an equivalent implementation for the BW16, I decided to build one myself as a way to learn more about the platform and Arduino development.
The animation is created by converting a video (or GIF) into monochrome bitmap frames using Image2CPP. The firmware then displays each frame sequentially on the SSD1306 display, creating the animation.

## **Features**
1. Frame-by-frame bitmap animation playback
2. 128×64 SSD1306 OLED support
3. Restart button
4. Easy to replace animation frames
5. Built with the Arduino framework
 
## **Libraries Used**
Adafruit SSD1306

Adafruit GFX Library

Wire (I²C)

## **How it Works**
Convert a video or GIF into individual monochrome frames.

Convert the frames into bitmap arrays using [Image2CPP](https://javl.github.io/image2cpp/).

Store the generated arrays in Animation.h.

The firmware displays each frame with a fixed delay, creating the animation.

### *Notes*

>This project was written primarily as a learning exercise.
>The code is intentionally simple and straightforward rather than highly optimized. There are certainly many ways it could be improved, but my main objective was to understand how the BW16 works and to create something functional.
>If this project helps someone else getting started with the BW16, then it has already achieved its purpose.

## Contributions, suggestions, and improvements are always welcome.
