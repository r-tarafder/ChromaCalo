/*#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

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
//#include "detector.hh"
#include "globals.hh"
//#include "G4SDManager.hh"
/*
class MyDetectorConstruction : public G4VUserDetectorConstruction {
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    virtual G4VPhysicalVolume *Construct();
    
    
private:
   
   // virtual void ConstructSDandField();
    G4LogicalVolume* logicShape1; // Declare logical volumes as member variables
    G4LogicalVolume* logicShape2;
    G4LogicalVolume* logicShape3;
    G4LogicalVolume* logicShape4;
    G4LogicalVolume* logicShape5;    
};

#endif*/


#ifndef DetectorConstruction_HH
#define DetectorConstruction_HH

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4GlobalMagFieldMessenger;

namespace upo
{

/// Detector construction class to define materials and geometry.
/// The calorimeter is a box made of a given number of layers. A layer consists
/// of an absorber plate and of a detection gap. The layer is replicated.
///
/// Four parameters define the geometry of the calorimeter :
///
/// - the thickness of an absorber plate,
/// - the thickness of a gap,
/// - the number of layers,
/// - the transverse size of the calorimeter (the input face is a square).
///
/// In addition a transverse uniform magnetic field is defined
/// via G4GlobalMagFieldMessenger class.

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction() = default;
    ~DetectorConstruction() override = default;

  public:
    G4VPhysicalVolume* Construct() override;
    void ConstructSDandField() override;

    // get methods
    //
    const G4VPhysicalVolume* Getshape1pv() const;
    const G4VPhysicalVolume* Getshape2pv() const;
    const G4VPhysicalVolume* Getshape3pv() const;
    const G4VPhysicalVolume* Getshape4pv() const;
    const G4VPhysicalVolume* Getshape5pv() const;

  private:
    // methods
    //
    void DefineMaterials();
    G4VPhysicalVolume* DefineVolumes();

    // data members
    //
    static G4ThreadLocal G4GlobalMagFieldMessenger*  fMagFieldMessenger;
                                      // magnetic field messenger

    G4VPhysicalVolume* shape1pv = nullptr; // the absorber physical volume
    G4VPhysicalVolume* shape2pv = nullptr;
    G4VPhysicalVolume* shape3pv = nullptr;
    G4VPhysicalVolume* shape4pv = nullptr;
    G4VPhysicalVolume* shape5pv = nullptr;// the gap physical volume

    G4bool fCheckOverlaps = true; // option to activate checking of volumes overlaps
};

// inline functions

inline const G4VPhysicalVolume* DetectorConstruction::Getshape1pv() const {
  return shape1pv;
}

inline const G4VPhysicalVolume* DetectorConstruction::Getshape1pv() const {
  return shape1pv;
}
inline const G4VPhysicalVolume* DetectorConstruction::Getshape1pv() const {
  return shape1pv;
}
inline const G4VPhysicalVolume* DetectorConstruction::Getshape1pv() const {
  return shape1pv;
}
inline const G4VPhysicalVolume* DetectorConstruction::Getshape1pv() const {
  return shape1pv;
}
v

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

