modded class Plastic_Explosive : ExplosivesBase
{
	override bool IsTakeable()
	{
		return true;
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return true;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return true;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (attachment && attachment.IsKindOf("DuctTape") && slotId == InventorySlots.GetSlotIdFromString("TapeSlot"))
		{
			ItemBase tape_HBE = ItemBase.Cast(attachment);
			if (tape_HBE && tape_HBE.GetQuantityNormalized() < 0.99)
			{
				return false; // Too little tape
			}
		}

		return super.CanReceiveAttachment(attachment, slotId);
	}

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		if (attachment && attachment.IsKindOf("DuctTape") && FindAttachmentBySlotName("TapeSlot") == attachment)
		{
			return false; // Lock tape in once added
		}
		return super.CanReleaseAttachment(attachment);
	}

	// Optional helper if needed elsewhere
	bool CanPlaceAnywhere_HBE()
	{
		return FindAttachmentBySlotName("TapeSlot") != null;
	}
}
