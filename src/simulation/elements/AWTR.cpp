#include "simulation/ElementCommon.h"

void Element::Element_AWTR()
{
	this->Identifier = "PT_AWTR";
	this->Name = "AWTR";
	this->Colour = 0x4DC9FF_rgb;
	this->MenuVisible = 1;
	this->MenuSection = SC_LIQUID;
	this->Enabled = 1;

	this->Advection = -0.62f;
	this->AirDrag = 0.01f;
	this->AirLoss = 0.98f;
	this->Loss = 0.95f;
	this->Collision = 0.0f;
	this->Gravity = -0.1f;
	this->Diffusion = 0.0f;
	this->HotAir = 0.0f;
	this->Falldown = 2;

    this->Flammable = 0;
    this->Explosive = 0;
    this->Meltable = 0;
    this->Hardness = 20;

	this->Weight = 30;

	this->DefaultProperties.temp = R_TEMP - 2.0f + 273.15f;
	this->HeatConduct = 30;
	this->Description = "Anti-Water. Negative gravity, doesn't conduct, doesn't freeze, and doesn't extinguish fires.";

	this->Properties = TYPE_LIQUID | PROP_LIFE_DEC | PROP_NEUTPASS | PROP_PHOTPASS;

	this->LowPressure = IPL;
	this->LowPressureTransition = NT;
	this->HighPressure = IPH;
	this->HighPressureTransition = NT;
	this->LowTemperature = ITL;
	this->LowTemperatureTransition = NT;
	this->HighTemperature = ITH;
	this->HighTemperatureTransition = NT;
}