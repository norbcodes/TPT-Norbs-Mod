#include "simulation/ElementCommon.h"

static int OzonUpdate(UPDATE_FUNC_ARGS)
{
    bool PressurePoint = sim->pv[y/CELL][x/CELL] < -100.0f;
    bool TempPoint = parts[i].temp < -112.0f + 273.15f;

    if (PressurePoint && TempPoint)
    {
        sim->kill_part(i);
        sim->create_part(i, x, y, PT_LO2);
        return -1;
    }

    if (PressurePoint)
    {
        sim->kill_part(i);
        sim->create_part(i, x, y, PT_O2);
        return -1;
    }

    if (TempPoint)
    {
        sim->kill_part(i);
        sim->create_part(i, x, y, PT_LOZN);
        return -1;
    }

    return 0;
}

void Element::Element_OZON()
{
    // Meta stuff
    this->Identifier = "PT_OZON";
    this->Name = "OZON";
    this->Description = "Ozone. Kills virus upon contact.";
    this->Properties = TYPE_GAS;
    this->Colour = 0xCCFFEE_rgb;
    this->MenuVisible = 1;
    this->MenuSection = SC_GAS;
    this->Enabled = 1;

    // Element physics
    this->Advection = 0.8f;
    this->AirDrag = 0.002f;
    this->AirLoss = 0.999f;
    this->Loss = 0.2f;
    this->Collision = -0.01f;
    this->Gravity = -0.01f;
    this->Diffusion = 2.3f;
    this->HotAir = 0.0f;
    this->Falldown = 0;
    this->Flammable = 0;
    this->Explosive = 0;
    this->Meltable = 0;
    this->Hardness = 1;
    this->Weight = 1;
    DefaultProperties.temp = R_TEMP + 273.15f;
    this->HeatConduct = 80;
    this->LowPressure = IPL;
	this->LowPressureTransition = NT;
	this->HighPressure = IPH;
	this->HighPressureTransition = NT;
	this->LowTemperature = ITL;
	this->LowTemperatureTransition = NT;
	this->HighTemperature = ITH;
	this->HighTemperatureTransition = NT;

    // Set callbacks
    this->Update = OzonUpdate;
}