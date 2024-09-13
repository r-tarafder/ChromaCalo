/*// MySensitiveDetector.cc

#include "detector.hh"


MySensitiveDetector::MySensitiveDetector(G4String name)
    : G4VSensitiveDetector(name) {}

MySensitiveDetector::~MySensitiveDetector() {}

//void MySensitiveDetector::Initialize(G4HCofThisEvent* HCE) {
    // Initialization code
//}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist) {
    // Processing hits code
    G4Track *track = aStep->GetTrack();
    track->SetTrackStatus(fStopAndKill);
    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
    G4ThreeVector posPhoton = preStepPoint->GetPosition();
    const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
    G4VPhysicalVolume *phyVol = touchable->GetVolume();
    G4ThreeVector posDetector = phyVol->GetTranslation();
    G4cout << "Detector position: " << posDetector << G4endl;
    
}

//void MySensitiveDetector::EndOfEvent(G4HCofThisEvent* HCE) {
    // End of event code
//}
*/
