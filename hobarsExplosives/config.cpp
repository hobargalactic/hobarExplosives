class CfgMods
{
	class hobarsExplosives
	{
		dir = "hobarsExplosives";
		name = "hobarsExplosives";
		author = "hobargalactic";
		version = "1.0";
		type = "mod";
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"hobarsExplosives/scripts/4_World"
				};
			};
		};
	};
};

class CfgPatches
{
	class hobarsExplosives
	{
		units[] =
		{
			"Plastic_Explosive"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Weapons_Explosives",
			"DZ_Gear_Consumables"
		};
	};
};

class CfgSlots
{
	class Slot_TapeSlot
	{
		name = "TapeSlot";
		displayName = "Duct Tape";
		ghostIcon = "hobarsExplosives/gui/images/inventory/tapeslot_icon";
	};
};

class CfgVehicles
{
	class ExplosivesBase;
	class Inventory_Base;

	class Plastic_Explosive : ExplosivesBase
	{
		scope = 2;
		attachments[] = 
		{ 
			"TriggerRemoteDetonator_Receiver",
			"TapeSlot"
		};
	};

	class DuctTape : Inventory_Base
	{
		scope = 2;
		inventorySlot[] = 
		{ 
			"TapeSlot" 
		};
	};
};
