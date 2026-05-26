#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>

#include "runtime_manager.h"

class RuntimeManager;

extern RuntimeManager* g_runtimeManager;

extern QString version;
extern QString model;
extern QString serial_no;

extern bool surgery_pause;

extern QString loginpass;
extern QString userpass;
extern QString adminpass;
extern double power980;
extern double power1470;
extern int TimerSec;
extern double currentJoule;
extern double currentAvgPower;
extern bool dark;
extern int pulseOnTime;
extern int pulseOffTime;
extern int alarmSeconds;
extern int alarmJoules;
extern int soundIntensity;
extern int beepIntensity;
extern int brightnessIntensity;
extern int aimingbeamIntensity;
extern bool timer_reset;
extern bool pulseMode;
extern QString current_protocol;
extern bool advancedmode;

// NEW variables
extern bool timerFlag;
extern bool audioMode;
extern double avarageEnergyJoule;
extern bool simpliAdvanMode;
extern QString protocolName;
extern bool persistence_data;
extern bool new_protocol;
extern bool modify_protocol;
extern bool password_enable;
extern bool patient_data;
extern bool interlock_key;
extern bool protocolModified;
extern double no_protocol_used;

#define MAX_ALLOWED_TIME 300.0f

extern float energyDelivered;             // Energy calculated when laser released
extern float storedEnergy[8];              // Store up to 8 energy values
extern int storedCount;                      // Number of stored values
extern float totalEnergyDelivered; // cumulative energy
extern float new_totalEnergyDelivered; // cumulative energy
extern float new2_totalEnergyDelivered; // cumulative energy
extern float liveTime;
extern bool Adv_Sim_fromSetting;
extern bool surgery_pause_bt;
extern bool last_theme_status;

extern float energyAtPress;
extern float energyPerPedal;
extern float last_energyPerPedal;
extern float energyAtRelease;

extern double avgPower;
extern bool startup_done;

extern double powerValue;
extern int dacAValue;
extern int dacBValue;

// Timer globals
extern int g_totalSystemMinutes;
extern qint64 g_surgery_ms;


extern qint64 g_diode1470Ms;
extern qint64 g_diode980Ms;
extern qint64 g_diode980Ms_persurgery;
extern qint64 g_diode1470Ms_persurgery;
extern int g_totalNoSurgeryDone;
extern int g_usageNoSurgeryDone;


extern int user_admin_mode;
extern bool clear_data;
extern bool clear_page;
extern bool custom_modify;

extern int pulsemode_step1;
extern int pulsemode_step2;
extern int pulsemode_step3;

struct Range {
    int low;
    int high;
    int step;
};

extern Range range1;
extern Range range2;
extern Range range3;

extern int pulseMinLimit;
extern int pulseMaxLimit;


#endif // GLOBAL_H
