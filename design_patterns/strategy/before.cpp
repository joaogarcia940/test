#include <iostream>
#include <cstdio>

// how would you implement share methods?
// we need one for text message, one for email
// with inheritance we would have to implement each sharing for each camera type
// what if we need a social media app? and more camera types? is this scalable?

class PhoneCameraApp {
public:
  virtual void Edit() = 0;
  virtual void ShareEmail() = 0;
  virtual void ShareTextMessage() = 0;
  void Take(){}
  void Save(){}
};

class BasicCameraApp : public PhoneCameraApp {
public:
  void Edit() override { printf("Editing from BasicCameraApp\n"); }
  void ShareEmail() override { printf("Sharing Email from BasicCameraApp\n"); }
  void ShareTextMessage() override { printf("Sharing Email from BasicCameraApp\n"); }
};

class CameraPlusApp : public PhoneCameraApp {
public:
  void Edit() override { printf("Editing from CameraPlusApp\n"); }
};

int main() {
  BasicCameraApp camera_app;
  camera_app.Edit();
  camera_app.ShareTextMessage();
  return 0;
}