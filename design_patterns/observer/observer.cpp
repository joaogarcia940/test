#include <vector>

class ISubject
{
public:
    void RegisterObserver(Observer o);
    void RemoveObserver(Observer o);
    void NotifyObserver();
};

class SimpleSubject : public ISubject
{
public:


private:
    std::vector<Observer> observers;
    int value = 0;
};
