#include <iostream>
#include <cstdio> // Include cstdio for printf

class PhoneCameraApp {
public:
  void Take(){};
  virtual void Edit() = 0;
  void Save(){};
  void Share(){}; // text and email rn, but a new way to share is needed to
                  // social media
};

class BasicCameraApp : public PhoneCameraApp {
public:
  void Edit() override { printf("Editing form BasicCameraApp"); }
};

class CameraPlusApp : public PhoneCameraApp {
public:
  void Edit() override { printf("Editing from CameraPlusApp"); }
};

int main() {
  std::cout << "Hello world" << std::endl;
  return 0;
}