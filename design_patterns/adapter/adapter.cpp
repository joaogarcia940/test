#include <iostream>

class IDuck
{
public:
    virtual void Quack() = 0;
    virtual void Fly() = 0;
};

class MallardDuck : public IDuck
{
public:
    void Quack() override
    {
        printf("Mallard Duck: quack!\n");
    }
    void Fly() override
    {
        printf("Mallard Duck: flies!\n");
    }
};

class ITurkey
{
public:
    virtual void Gobble() = 0;
    virtual void Fly() = 0;
};

class WildTurkey : public ITurkey
{
public:
    void Gobble() override
    {
        printf("Wild Turkey: gobble gobble!\n");
    }
    void Fly() override
    {
        printf("Wild Turkey: flies!\n");
    }
};

class IDrone
{
public:
    virtual void Beep() = 0;
    virtual void SpinRotors() = 0;
    virtual void TakeOff() = 0;
};

class SuperDrone : public IDrone
{
public:
    void Beep() override
    {
        printf("Super Drone: beep!\n");
    }
    void SpinRotors() override
    {
        printf("Super Drone: spin rotors!\n");
    }
    void TakeOff() override
    {
        printf("Super Drone: take off!\n");
    }
};

class DuckSimulator
{
public:
    void TestDuck(IDuck &duck)
    {
        duck.Quack();
        duck.Fly();
    }
};

class WildTurkeyAdapter : public IDuck
{
public:
    explicit WildTurkeyAdapter(ITurkey &i_turkey) : i_turkey_{i_turkey} {}
    void Quack() override
    {
        i_turkey_.Gobble();
    }
    void Fly() override
    {
        i_turkey_.Fly();
    }

private:
    ITurkey &i_turkey_;
};

class DroneAdapter : public IDuck
{
public:
    explicit DroneAdapter(IDrone &i_drone) : i_drone_{i_drone} {}
    void Quack() override
    {
        i_drone_.Beep();
    }
    void Fly() override
    {
        i_drone_.SpinRotors();
        i_drone_.TakeOff();
        printf("Super Drone: flies!");
    }

private:
    IDrone &i_drone_;
};

int main()
{
    MallardDuck duck;
    DuckSimulator duck_simulator;
    duck_simulator.TestDuck(duck);
    WildTurkey turkey;
    WildTurkeyAdapter turkey_adapter{turkey};
    duck_simulator.TestDuck(turkey_adapter);
    SuperDrone drone;
    DroneAdapter drone_adapter{drone};
    duck_simulator.TestDuck(drone_adapter);
    return 0;
}