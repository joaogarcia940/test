#include <iostream>
#include <cstdio>

class IShareStrategy
{
  public:
  virtual void Share() = 0;
};

class ShareTextMessageStrategy : public IShareStrategy
{
  public:
  void Share() override { printf("Sharing text message...\n");}
};

class ShareEmailStrategy : public IShareStrategy
{
  public:
  void Share() override { printf("Sharing email...\n");}
};

class ShareSocialMediaStrategy : public IShareStrategy
{
  public:
  void Share() override { printf("Sharing social media...\n");}
};

class PhoneCameraApp {
public:
  virtual void Edit() = 0;
  void Take(){}
  void Save(){}
  void Share(IShareStrategy& i_share)
  {
    i_share.Share();
  }
};

class BasicCameraApp : public PhoneCameraApp {
public:
  void Edit() override { printf("Editing from BasicCameraApp\n"); }
};

class CameraPlusApp : public PhoneCameraApp {
public:
  void Edit() override { printf("Editing from CameraPlusApp\n"); }
};

int main() {
  BasicCameraApp camera_app;
  camera_app.Edit();
  ShareTextMessageStrategy share;
  camera_app.Share(share);
  return 0;
}