#ifndef MYSTEPPINGACTION_HH
#define MYSTEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include <map>

class MySteppingAction : public G4UserSteppingAction {
public:
    MySteppingAction();
    virtual ~MySteppingAction();

    virtual void UserSteppingAction(const G4Step* step) override;

    void PrintDeposits();
    void Reset();

private:
    std::map<G4LogicalVolume*, G4double> energyDeposits;
};

#endif // MYSTEPPINGACTION_HH

