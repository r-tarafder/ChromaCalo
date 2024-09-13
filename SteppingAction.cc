#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
//#include "detector.hh"
#include "construction.hh"
//#include "TFile.h"
//#include "TTree.h"
#include "EventAction.hh"
/*SteppingAction::SteppingAction() {
    fRootFile = new TFile("energyDeposition.root", "RECREATE");
    fTree = new TTree("EdepTree", "Energy deposition in volumes");
    fTree->Branch("Edep", fEdep, "Edep[5]/D");

    for (int i = 0; i < 5; i++) {
        fEdep[i] = 0.;
    }
}

SteppingAction::~SteppingAction() {
    fRootFile->Write();
    fRootFile->Close();
    delete fRootFile;
}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    G4LogicalVolume* volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
    G4double edep = step->GetTotalEnergyDeposit();

    DetectorConstruction* detectorConstruction = static_cast<DetectorConstruction*>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());

    for (int i = 0; i < 5; i++) {
        if (volume == detectorConstruction->GetVolume(i)) {
            fEdep[i] += edep;
            break;
        }
    }

    if (step->GetTrack()->GetTrackID() == 1 && step->GetTrack()->GetTrackStatus() == fStopAndKill) {
        fTree->Fill();
        for (int i = 0; i < 5; i++) {
            fEdep[i] = 0.;
        }
    }
}
*/

using namespace upo;

namespace upo
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(const DetectorConstruction* detConstruction,
                               EventAction* eventAction)
  : fDetConstruction(detConstruction),
    fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* step)
{
// Collect energy and track length step by step

  // get volume of the current step
  auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();

  // energy deposit
  auto edep = step->GetTotalEnergyDeposit();

  // step length
  G4double stepLength = 0.;
  if ( step->GetTrack()->GetDefinition()->GetPDGCharge() != 0. ) {
    stepLength = step->GetStepLength();
  }

  if ( volume == fDetConstruction->Getshape1pv() ) {
    fEventAction->Addshape1pv(edep,stepLength);
  }

  if ( volume == fDetConstruction->Getshape2pv() ) {
    fEventAction->Addshape2pv(edep,stepLength);
  }
  
   if ( volume == fDetConstruction->Getshape3pv() ) {
    fEventAction->Addshape3pv(edep,stepLength);
  }
  
   if ( volume == fDetConstruction->Getshape4pv() ) {
    fEventAction->Addshape4pv(edep,stepLength);
  }
  
   if ( volume == fDetConstruction->Getshape5pv() ) {
    fEventAction->Addshape5pv(edep,stepLength);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
