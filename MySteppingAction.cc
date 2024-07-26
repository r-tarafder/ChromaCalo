#include "MySteppingAction.hh"

MySteppingAction::MySteppingAction() {}

MySteppingAction::~MySteppingAction() {}

void MySteppingAction::UserSteppingAction(const G4Step* step) {
    // Get the energy deposit for this step
    G4double edep = step->GetTotalEnergyDeposit();

    // Get the volume in which the step occurs
    G4LogicalVolume* volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

    // Accumulate the energy deposit for each volume
    if (edep > 0) {
        energyDeposits[volume] += edep;
    }
}

void MySteppingAction::PrintDeposits() {
    for (const auto& entry : energyDeposits) {
        G4cout << "Volume: " << entry.first->GetName()
               << ", Energy deposited: " << entry.second / keV << " keV" << G4endl;
    }
}

void MySteppingAction::Reset() {
    energyDeposits.clear();
}

