#include "simulation/ElementCommon.h"

static int NpumUpdate(UPDATE_FUNC_ARGS)
{
    if ( sim->rng.chance(1, 500) && sim->rng.chance( static_cast<int>(5.0f*sim->pv[y/CELL][x/CELL]) , 1800) )
	{
		sim->create_part(i, x, y, PT_NEUT);
        sim->create_part(i, x, y, PT_NEUT);
	}
    return 0;
}

void Element::Element_NPUM()
{
    // Meta stuff
    this->Identifier = "PT_NPUM";
    this->Name = "NPUM";
    this->Colour = 0xB3CCFF_rgb;
    this->MenuVisible = 1;
    this->MenuSection = SC_NUCLEAR;
    this->Enabled = 1;
    this->Description = "Neptunium. Goes supercritical way later than plutonium while generating more temp.";
    this->Properties = TYPE_PART | PROP_NEUTPASS | PROP_DEADLY | PROP_RADIOACTIVE;
    this->CarriesTypeIn = 0;

    // Physics
    this->Advection = 0.4f;
    this->AirDrag = 0.01f;
    this->AirLoss = 0.7f;
    this->Loss = 0.95f;
    this->Collision = 0.0f;
    this->Gravity = 0.5f;
    this->Diffusion = 0.0f;
    this->HotAir = 0.0000001f;
    this->Falldown = 1;
    this->Flammable = 0;
    this->Explosive = 0;
    this->Meltable = 1;
    this->Hardness = 2;
    this->PhotonReflectWavelengths = 0x00B3CCFF;
    this->Weight = 96;
    this->DefaultProperties.temp = R_TEMP + 273.15f;
    this->HeatConduct = 254;

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
    this->Update = NpumUpdate;
}