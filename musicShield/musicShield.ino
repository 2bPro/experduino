#include <SPI.h>
#include <SD.h>
#include <MusicPlayer.h>

MusicPlayer player;
String tracks = {"test1.mp3", "test2.mp3"};

void setup() {
  Serial.begin(115200);
  player.begin();
}

void loop() {
  //Play all tracks on the SD card
  player.play();

  //Play certain track
  //User-written method in libraries/MusicShield/MusicPlayer.cpp, line 213
  player.playTrack(tracks[0]);
}
