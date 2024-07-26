#include "MyEventAction.hh"

MyEventAction::MyEventAction(MySteppingAction* steppingAction)
    : fSteppingAction(steppingAction) {}

MyEventAction::~MyEventAction() {}

void MyEventAction::BeginOfEventAction(const G4Event* event) {
    fSteppingAction->Reset();
}

void MyEventAction::EndOfEventAction(const G4Event* event) {
    G4cout << "Event " << event->GetEventID() << " summary:" << G4endl;
    fSteppingAction->PrintDeposits();
}

