#ifndef MYEVENTACTION_HH
#define MYEVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "MySteppingAction.hh"

class MyEventAction : public G4UserEventAction {
public:
    MyEventAction(MySteppingAction* steppingAction);
    virtual ~MyEventAction();

    virtual void BeginOfEventAction(const G4Event* event) override;
    virtual void EndOfEventAction(const G4Event* event) override;

private:
    MySteppingAction* fSteppingAction;
};

#endif // MYEVENTACTION_HH

