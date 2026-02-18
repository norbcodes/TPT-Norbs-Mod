#include "simulation/ElementCommon.h"

static int LoznUpdate(UPDATE_FUNC_ARGS)
{
    bool TempPoint = parts[i].temp > -112.0f + 273.15f;

    if (TempPoint)
    {
        sim->kill_part(i);
        sim->create_part(i, x, y, PT_OZON);
        return -1;
    }

    return 0;
}

void Element::Element_LOZN()
{
    // Meta stuff
    this->Identifier = "PT_LOZN";
    this->Name = "LOZN";
    this->Description = "Liquid Ozone. Kills virus upon contact.";
    this->Properties = TYPE_LIQUID;
    this->Colour = 0x0073E6_rgb;
    this->MenuVisible = 1;
    this->MenuSection = SC_LIQUID;
    this->Enabled = 1;

    // Element physics
    this->Advection = 0.6f;
    this->AirDrag = 0.01f;
    this->AirLoss = 0.999f;
    this->Loss = 0.94f;
    this->Collision = 0.0f;
    this->Gravity = 0.102f;
    this->Diffusion = 0.0f;
    this->HotAir = 0.0f;
    this->Falldown = 2;
    this->Flammable = 0;
    this->Explosive = 0;
    this->Meltable = 0;
    this->Hardness = 0;
    this->Weight = 30;
    DefaultProperties.temp = -200.0f + 273.15f;
    this->HeatConduct = 80;
    this->LowPressure = IPL;
	this->LowPressureTransition = NT;
	this->HighPressure = IPH;
	this->HighPressureTransition = NT;
	this->LowTemperature = ITL;
	this->LowTemperatureTransition = NT;
	this->HighTemperature = ITH;
	this->HighTemperatureTransition = NT;

    // Set callback
    this->Update = LoznUpdate;
}