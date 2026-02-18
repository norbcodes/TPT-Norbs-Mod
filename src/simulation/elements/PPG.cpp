#include "simulation/ElementCommon.h"

static int PPG_Update(UPDATE_FUNC_ARGS)
{
    Particle& P = parts[i];
    if (P.life == 0)
    {
        P.life = P.tmp2;
        sim->pv[y/CELL][x/CELL] = (P.tmp) ? -P.temp : P.temp;
    }
    return 0;
}

void Element::Element_PPG()
{
    // Meta
    this->Identifier = "PT_PPG";
    this->Name = "PPG";
    this->Colour = 0xBBBBBB_rgb;
    this->MenuVisible = 1;
    this->MenuSection = SC_FORCE;
    this->Enabled = 1;
    this->Description = "Pressure Pulse Generator. Set strength using 'temp' "
                        "and set frames between pulse using 'tmp2'. Set 'tmp' to 1 for negative pressure.";
    this->Properties = TYPE_SOLID | PROP_LIFE_DEC;
    this->CarriesTypeIn = 0;

    // Physics
    this->Advection = 0.0f;
    this->AirDrag = 0.0f;
    this->AirLoss = 0.99f;
    this->Loss = 0.0f;
    this->Collision = 0.0f;
    this->Gravity = 0.0f;
    this->Diffusion = 0.0f;
    this->HotAir = 0.0f;
    this->Falldown = 0;
    this->Flammable = 0;
    this->Explosive = 0;
    this->Meltable = 0;
    this->Hardness = 0;
    this->PhotonReflectWavelengths = 0xffffffff;
    this->Weight = 100;
    this->DefaultProperties.temp = 0;
    this->DefaultProperties.tmp2 = 60;
    this->HeatConduct = 0;

    // State changes
    this->LowPressure = IPL;
	this->LowPressureTransition = NT;
	this->HighPressure = IPH;
	this->HighPressureTransition = NT;
	this->LowTemperature = ITL;
	this->LowTemperatureTransition = NT;
	this->HighTemperature = ITH;
	this->HighTemperatureTransition = NT;

    // Callbacks
    this->Update = PPG_Update;
}