/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/WPILib.h>
#include "OI.h"
#include "commands/HatchPanelEject.h"
#include "commands/GamePieceManipulatorManual.h"

/* ****
 *
 * 	xBox Controller button mapping:
 * 	Button 1 - A - 
 * 	Button 2 - B - 
 * 	Button 3 - X - 
 * 	Button 4 - Y - 
 * 	Button 5 - Left Bumper - 
 * 	Button 6 - Right Bumper - 
 * 	Button 7 - Back - 
 * 	Button 8 - Start - 
 * 	Button 9 - Left Stick
 * 	Button 10 - Right Stick
 */

OI::OI() {
  // Process operator interface input here.
  m_XboxDriver = new frc::XboxController(0); // Driver in USB slot zero
  m_XboxCoDriver = new frc::XboxController(1); // Driver in USB slot one

  btnEjectHatchPanel = new frc::JoystickButton(m_XboxDriver, 1);    // A button
  btnUtilityLight = new frc::JoystickButton(m_XboxDriver, 2);       // Cargo/Hatch Panel indicator
//  btnIntakeCargoBall = new frc::JoystickButton(m_XboxDriver, 3);
//  btnEjectCargoBall = new frc::JoystickButton(m_XboxDriver, 4);
  btnRaiseGamePieceManipulator = new frc::JoystickButton(m_XboxDriver, 5);
  btnLowerGamePieceManipulator = new frc::JoystickButton(m_XboxDriver, 6);
//  btnHABLift = new frc::JoystickButton();
//  btnHABRetractFront = new frc::JoystickButton();
//  btnHABRetractRear = new frc::JoystickButton();
//  btnHABForward = new frc::JoystickButton();
//  btnHABReverse = new frc::JoystickButton();
  btnEjectHatchPanel->WhileHeld(new HatchPanelEject);
  
  btnRaiseGamePieceManipulator->WhileHeld(new GamePieceManipulatorManual(1.0));
  btnLowerGamePieceManipulator->WhileHeld(new GamePieceManipulatorManual(-1.0));
}
