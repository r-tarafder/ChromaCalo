#include "construction.hh"

/*DetectorConstruction::DetectorConstruction()
{}

DetectorConstruction::~DetectorConstruction()
{}*/

MyDetectorConstruction::MyDetectorConstruction() : G4VUserDetectorConstruction() {}
MyDetectorConstruction::~MyDetectorConstruction() {}
G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
   G4NistManager *nist = G4NistManager::Instance();
   
   // Envelope parameters
  //
  
  G4double env_sizeXY = 4*cm, env_sizeZ = 120*cm;
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_AIR");
  
   // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;
  
//
  // World
  //
  G4double world_sizeXY = 1*env_sizeXY;
  G4double world_sizeZ  = 1*env_sizeZ;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

  auto solidWorld = new G4Box("World",                           // its name
    0.5 * world_sizeXY, 0.5 * world_sizeXY, 0.5 * world_sizeZ);  // its size

  auto logicWorld = new G4LogicalVolume(solidWorld,  // its solid
    world_mat,                                       // its material
    "World");                                        // its name

  auto physWorld = new G4PVPlacement(nullptr,  // no rotation
    G4ThreeVector(),                           // at (0,0,0)
    logicWorld,                                // its logical volume
    "World",                                   // its name
    nullptr,                                   // its mother  volume
    false,                                     // no boolean operation
    0,                                         // copy number
    checkOverlaps);                            // overlaps checking

  //
  // Envelope
  //
  auto solidEnv = new G4Box("Envelope",                    // its name
    0.5 * env_sizeXY, 0.5 * env_sizeXY, 0.5 * env_sizeZ);  // its size

  auto logicEnv = new G4LogicalVolume(solidEnv,  // its solid
    env_mat,                                     // its material
    "Envelope");                                 // its name

  new G4PVPlacement(nullptr,  // no rotation
    G4ThreeVector(),          // at (0,0,0)
    logicEnv,                 // its logical volume
    "Envelope",               // its name
    logicWorld,               // its mother  volume
    false,                    // no boolean operation
    0,                        // copy number
    checkOverlaps);           // overlaps checking

  //
  // Shape 1
  //
 
   G4Material *shape1_mat = new G4Material("Gd3Ga3Al2O12", 6.63*g/cm3, 4);
   shape1_mat->AddElement(nist->FindOrBuildElement("Gd"), 3);
   shape1_mat->AddElement(nist->FindOrBuildElement("Ga"), 3);
   shape1_mat->AddElement(nist->FindOrBuildElement("Al"), 2);  
   shape1_mat->AddElement(nist->FindOrBuildElement("O"), 12);                                                       
   
   
  // for Cuboid
  G4double half1X = 2 * cm;
  G4double half1Y = 2 * cm;
  G4double half1Z = 2 * cm;
  
  auto solidShape1 = new G4Box("GAGG", half1X, half1Y, half1Z);

  auto logicShape1 = new G4LogicalVolume(solidShape1,  // its solid
    shape1_mat,                                        // its material
    "GAGG");                                         // its name


  // Create visual attributes and set the color to yellow
  G4VisAttributes* shape1visAttributes = new G4VisAttributes(G4Colour(1.0, 1.0, 0.0)); // Yellow color
  logicShape1->SetVisAttributes(shape1visAttributes);
  
                 
                                  
  G4ThreeVector pos1 = G4ThreeVector(0, 0, 2*cm);


 shape1pv = new G4PVPlacement(nullptr,  // no rotation
    pos1,                     // at position
    logicShape1,              // its logical volume
    "GAGG",                 // its name
    logicEnv,                 // its mother  volume
    false,                    // no boolean operation
    0,                        // copy number
    true);           // overlaps checking

  //
  //Shape 2
  //
  
  
   G4Material *shape2_mat = new G4Material("PbWO4", 8.28*g/cm3, 3);
   shape2_mat->AddElement(nist->FindOrBuildElement("Pb"), 1);
   shape2_mat->AddElement(nist->FindOrBuildElement("W"), 1);
   shape2_mat->AddElement(nist->FindOrBuildElement("O"), 4);
   
  
 
  // Cuboid shape
  G4double half2X = 2 * cm;
  G4double half2Y = 2 * cm;
  G4double half2Z = 6 * cm;
  auto solidShape2 = new G4Box("PWO",  // its name
   half2X, half2Y, half2Z);  // its size

  auto logicShape2 = new G4LogicalVolume(solidShape2,  // its solid
    shape2_mat,                                        // its material
    "PWO");                                         // its name
    
     // Create visual attributes and set the color to Magenta
  G4VisAttributes* shape2visAttributes = new G4VisAttributes(G4Colour(1.0, 0.0, 1.0)); // Magenta color
  logicShape2->SetVisAttributes(shape2visAttributes);
  
  
   G4ThreeVector pos2 = G4ThreeVector(0, 0, 10*cm);

 shape2pv = new G4PVPlacement(nullptr,  // no rotation
    pos2,                     // at position
    logicShape2,              // its logical volume
    "PWO",                 // its name
    logicEnv,                 // its mother  volume
    false,                    // no boolean operation
    0,                        // copy number
    true);           // overlaps checking
    
     //
// Shape 3
  //
  
   G4Material *shape3_mat = new G4Material("Bi4Ge3O12", 7.12*g/cm3, 3);
   shape3_mat->AddElement(nist->FindOrBuildElement("Bi"), 4);
   shape3_mat->AddElement(nist->FindOrBuildElement("Ge"), 3);  
   shape3_mat->AddElement(nist->FindOrBuildElement("O"), 12);                                                                         
     
     
  // for Cuboid
  G4double half3X = 2 * cm;
  G4double half3Y = 2 * cm;
  G4double half3Z = 3 * cm;
  auto solidShape3 = new G4Box("BGO", half3X, half3Y, half3Z);

  auto logicShape3 = new G4LogicalVolume(solidShape3,  // its solid
    shape3_mat,                                        // its material
    "BGO");                                         // its name
    
    // Create visual attributes and set the color to cyan
  G4VisAttributes* shape3visAttributes = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0)); // Cyan color
  logicShape3->SetVisAttributes(shape3visAttributes);
  
  
                             
  G4ThreeVector pos3 = G4ThreeVector(0, 0, 19*cm);

 shape3pv = new G4PVPlacement(nullptr,  // no rotation
    pos3,                     // at position
    logicShape3,              // its logical volume
    "BGO",                 // its name
    logicEnv,                 // its mother  volume
    false,                    // no boolean operation
    0,                        // copy number
    true);           // overlaps checking
    
     //
  // Shape 4
  //
  
   G4Material *shape4_mat = new G4Material("PbWO4", 8.28*g/cm3, 3);
   shape4_mat->AddElement(nist->FindOrBuildElement("Pb"), 1);
   shape4_mat->AddElement(nist->FindOrBuildElement("W"), 1);
   shape4_mat->AddElement(nist->FindOrBuildElement("O"), 4);   
   
  
  // for Cuboid
  G4double half4X = 2 * cm;
  G4double half4Y = 2 * cm;
  G4double half4Z = 12 * cm;
  auto solidShape4 = new G4Box("PWO4", half4X, half4Y, half4Z);

  auto logicShape4 = new G4LogicalVolume(solidShape4,  // its solid
    shape4_mat,                                        // its material
    "PWO4");                                         // its name
    
      // Create visual attributes and set the color to Red
  G4VisAttributes* shape4visAttributes = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0)); // Red color
  logicShape4->SetVisAttributes(shape4visAttributes);                                                                
                                  
  G4ThreeVector pos4 = G4ThreeVector(0, 0, 34*cm);

 shape4pv = new G4PVPlacement(nullptr,  // no rotation
    pos4,                     // at position
    logicShape4,              // its logical volume
    "PWO4",                 // its name
    logicEnv,                 // its mother  volume
    false,                    // no boolean operation
    0,                        // copy number
    true);           // overlaps checking
    
     //
  // Shape 5
  //
  
   G4Material *shape5_mat = new G4Material("LuYSiO5", 7.10*g/cm3, 4);
   shape5_mat->AddElement(nist->FindOrBuildElement("Lu"), 1);
   shape5_mat->AddElement(nist->FindOrBuildElement("Y"), 1);
   shape5_mat->AddElement(nist->FindOrBuildElement("Si"), 1);  
   shape5_mat->AddElement(nist->FindOrBuildElement("O"), 5);
   
   
  // for Cuboid
  G4double half5X = 2 * cm;
  G4double half5Y = 2 * cm;
  G4double half5Z = 2 * cm;
  auto solidShape5 = new G4Box("LYSO", half5X, half5Y, half5Z);

  auto logicShape5 = new G4LogicalVolume(solidShape5,  // its solid
    shape5_mat,                                        // its material
    "LYSO");                                         // its name
    
    // Create visual attributes and set the color to blue
  G4VisAttributes* shape5visAttributes = new G4VisAttributes(G4Colour(0.0, 0.0, 1.0)); // Blue color
  logicShape5->SetVisAttributes(shape5visAttributes);                                                                         
                                  
  G4ThreeVector pos5 = G4ThreeVector(0, 0, 48*cm);

 shape5pv = new G4PVPlacement(nullptr,  // no rotation
    pos5,                     // at position
    logicShape5,              // its logical volume
    "LYSO",                 // its name
    logicEnv,                 // its mother  volume
    false,                    // no boolean operation
    0,                        // copy number
    true);           // overlaps checking


  // Set all Shapes as scoring volume
  //
 // G4Box *solidDetector = new G4Box("solidDetector", 0.005*cm, 0.005*cm, 1*cm);
  
  //ogicDetector = new G4LogicalVolume(solidDetector, world_mat, "logicDetector");

 /* for(G4int i = 0; i < 10; i++)

{
     for(G4int j = 0; j < 10; j++)
     {
        G4VPhysicalVolume *physDetector = new G4PVPlacement(0,
         G4ThreeVector(-2*cm+(i+0.5)*cm/10, -2*cm+(j+0.5)*cm/10, 58*cm),
          logicDetector, "physDetector", logicWorld, false, j+i*10, true);
     }
}*/



  //
  //always return the physical World
  //


  
  return physWorld;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::ConstructSDandField()
{
  // Create global magnetic field messenger.
  // Uniform magnetic field is then created automatically if
  // the field value is not zero.
  G4ThreeVector fieldValue;
  fMagFieldMessenger = new G4GlobalMagFieldMessenger(fieldValue);
  fMagFieldMessenger->SetVerboseLevel(1);

  // Register the field messenger for deleting
  G4AutoDelete::Register(fMagFieldMessenger);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}

 //void MyDetectorConstruction::ConstructSDandField() {
  //  G4SDManager *SDman = G4SDManager::GetSDMpointer();
    
   // MySensitiveDetector* mySD = new MySensitiveDetector("MySD");
    //SDman->AddNewDetector(mySD);

    // Assign the sensitive detector to volumes
   /* G4LogicalVolume* volume1 = logicShape1; // Get your logical volume 1
    G4LogicalVolume* volume2 = logicShape2; // Get your logical volume 2
    G4LogicalVolume* volume3 = logicShape3; // Get your logical volume 3
    G4LogicalVolume* volume4 = logicShape4; // Get your logical volume 4
    G4LogicalVolume* volume5 = logicShape5; // Get your logical volume 5*/

   /* volume1->SetSensitiveDetector(mySD);
    volume2->SetSensitiveDetector(mySD);
    volume3->SetSensitiveDetector(mySD);
    volume4->SetSensitiveDetector(mySD);
    volume5->SetSensitiveDetector(mySD);
    
    
    logicShape1->SetSensitiveDetector(mySD);
    logicShape2->SetSensitiveDetector(mySD);
    logicShape3->SetSensitiveDetector(mySD);
    logicShape4->SetSensitiveDetector(mySD);
    logicShape5->SetSensitiveDetector(mySD);*/
}

  


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



