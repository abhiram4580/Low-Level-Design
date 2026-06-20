#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Notification{
    public:
    virtual void notifyUser(string message)=0;
    virtual ~Notification() {};
};

class EmailNotification: public Notification{
   public:
    void notifyUser (string message) override{
      cout<<"[Email Notification] You have recieved a  "<<message<<endl;
   }
};

class SMSNotification: public Notification{
    public:
    void notifyUser (string message)override{
      cout<<"[SMS Notification] You have recieved a  "<<message<<endl;
    }
};

class PushNotification: public Notification{
    public:
    void notifyUser (string message)override{
        cout<<"[Push Notification] You have recieved a  "<<message<<endl;
    }
};


class NotificationChannel{
    private:
    Notification *notification;
    public:
    NotificationChannel(Notification *notification){
        this->notification=notification;
    }

    void messageUser(string message){
        notification->notifyUser(message);
    }
};



int main(){
    PushNotification p1;
    NotificationChannel n1(&p1);
    n1.messageUser("Text Message");

    SMSNotification s1;
    NotificationChannel n2(&s1);
    n2.messageUser("Text Message");

    EmailNotification e1;
    NotificationChannel n3(&e1);
    n3.messageUser("Text Message");

    return 0;
}