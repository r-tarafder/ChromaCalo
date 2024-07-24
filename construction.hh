#ifndef CONSTRUCTION_ΗΗ
#define CONSTRUCTION_ΗΗ

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "detector.hh"
class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
      MyDetectorConstruction();
      ~MyDetectorConstruction();
      virtual G4VPhysicalVolume *Construct();
      
     // virtual void ConstructSDandField();
      
//private:
  //     G4LogicalVolume *logicDetector;
    //   virtual void ConstrucSDandField();
      
};
#endif
