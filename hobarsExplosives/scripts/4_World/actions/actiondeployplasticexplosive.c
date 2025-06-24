modded class ActionDeployObject
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Plastic_Explosive explosive = Plastic_Explosive.Cast(item);

		if (explosive && explosive.FindAttachmentBySlotName("TapeSlot"))
		{
			vector from;
			vector to;
			MiscGameplayFunctions.GetHeadBonePos(player, from);
			vector dir = GetGame().GetCurrentCameraDirection();
			to = from + dir * 2.0;

			vector hitPos, hitNormal;
			int component;
			Object hitObject;
			set<Object> hitResults = new set<Object>();

			bool hit = DayZPhysics.RaycastRV(from, to, hitPos, hitNormal, component, hitResults, explosive, player, false, false);
			if (hit && hitResults.Count() > 0)
			{
				hitObject = hitResults.Get(0);

				player.SetLocalProjectionPosition(hitPos);

				// Fixed orientation logic
				vector orientation = vector.Direction(hitNormal, "0 1 0");
				player.SetLocalProjectionOrientation(orientation);

				return true;
			}

			return false;
		}

		return super.ActionCondition(player, target, item);
	}

	override bool ActionConditionContinue(ActionData action_data)
	{
		Plastic_Explosive explosive = Plastic_Explosive.Cast(action_data.m_MainItem);

		if (explosive && explosive.FindAttachmentBySlotName("TapeSlot"))
			return true;

		return super.ActionConditionContinue(action_data);
	}
}
