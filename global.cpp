#include "global.h"

//********************************************************************
QString version = "Hv_1.1";
QString model = "Dual Diode";
QString serial_no = "HDD_001";
//********************************************************************

RuntimeManager* g_runtimeManager = nullptr;

bool surgery_pause = 0;

QString loginpass = "";
QString userpass = "";
QString adminpass = "";
double power980 = 0.0;
double power1470 = 0.0;
int TimerSec = 1;
double currentJoule = 0.0;
double currentAvgPower = 0.0;
bool dark = false;
int pulseOnTime = 50;
int pulseOffTime = 50;
int alarmSeconds = 1;
int alarmJoules = 0;
int soundIntensity = 5;
int beepIntensity = 5;
int brightnessIntensity = 1;
int aimingbeamIntensity = 1;
bool timer_reset = false;
bool pulseMode = false;
QString current_protocol = "";

// NEW variables
bool timerFlag = false;
bool audioMode = false;
double avarageEnergyJoule = 0.0;
bool simpliAdvanMode = false;
QString protocolName = "";
bool persistence_data = true;
bool new_protocol = false;
bool modify_protocol = false;
bool password_enable = false;
bool patient_data = false;
bool interlock_key = false;
bool protocolModified = false;
double no_protocol_used = 0;

float energyDelivered = 0.0f;             // Energy calculated when laser released
float storedEnergy[8] = {0};              // Store up to 8 energy values
int storedCount = 0;                      // Number of stored values
float totalEnergyDelivered = 0.0f; // cumulative energy
float new_totalEnergyDelivered = 0.0f; // cumulative energy
float new2_totalEnergyDelivered = 0.0f; // cumulative energy
float liveTime = 0.0f;
bool Adv_Sim_fromSetting = 0;
bool surgery_pause_bt = 0;
bool last_theme_status = 0;
int override_popup = 0;

float energyAtPress = 0.0f;
float energyPerPedal = 0.0f;
float last_energyPerPedal = 0.0f;
float energyAtRelease = 0.0f;

double avgPower = 0.0;
bool startup_done = false;

double powerValue = 0.0;
int dacAValue = 0;
int dacBValue = 0;
int g_stackIndex = 0;

int g_totalSystemMinutes = 0;
qint64 g_surgery_ms = 0;

qint64 g_diode1470Ms = 0;
qint64 g_diode980Ms = 0;
qint64 g_diode980Ms_persurgery = 0;
qint64 g_diode1470Ms_persurgery = 0;
int g_totalNoSurgeryDone = 0;
int g_usageNoSurgeryDone = 0;



int user_admin_mode = 0;
bool clear_data = 0 ;
bool clear_page = 0;
bool custom_modify = 0;

int pulsemode_step1 = 50;
int pulsemode_step2 = 50;
int pulsemode_step3 = 50;

Range range1 = {0, 500, 50};
Range range2 = {500, 1500, 50};
Range range3 = {1500, 3000, 50};

int pulseMinLimit = 50;          // 50us
int pulseMaxLimit = 12000000;    // 12s



