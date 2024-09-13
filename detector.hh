/*#ifndef DETECTOR_HH
#define DETECTOR_HH
#include "G4VSensitiveDetector.hh"
//#include "G4HCofThisEvent.hh"

class MySensitiveDetector: public G4VSensitiveDetector
{
public:
     MySensitiveDetector(G4String);
     ~MySensitiveDetector();
     
 private:
   // virtual void Initialize(G4HCofThisEvent* HCE) override;
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
   // virtual void EndOfEvent(G4HCofThisEvent* HCE) override;
};

#endif
*/
