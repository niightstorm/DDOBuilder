// SpellSchoolTypes.h
//
#pragma once

#include "XmlLib\SaxContentElement.h"

// Special note - The  "Unknown" entries of each enum must be entry 0 in the
// enum map as this is used by the SAX loaders to check for badly loaded values
// these enumerations are used across multiple object types
enum SpellSchoolType
{
    SpellSchool_Unknown = 0,
    SpellSchool_Abjuration,
    SpellSchool_All,
    SpellSchool_Conjuration,
    SpellSchool_Divination,
    SpellSchool_DragonBreath,
    SpellSchool_Enchantment,
    SpellSchool_Evocation,
    SpellSchool_Illusion,
    SpellSchool_Necromancy,
    SpellSchool_Transmutation,
    SpellSchool_Wands,
    SpellSchool_InnateAttack,
    SpellSchool_BreathWeapon,
};
const XmlLib::enumMapEntry<SpellSchoolType> spellSchoolTypeMap[] =
{
    {SpellSchool_Unknown, L"Unknown"},
    {SpellSchool_Abjuration, L"Abjuration"},
    {SpellSchool_All, L"All"},
    {SpellSchool_Conjuration, L"Conjuration"},
    {SpellSchool_Divination, L"Divination"},
    {SpellSchool_DragonBreath, L"DragonBreath"},
    {SpellSchool_Enchantment, L"Enchantment"},
    {SpellSchool_Evocation, L"Evocation"},
    {SpellSchool_Illusion, L"Illusion"},
    {SpellSchool_Necromancy, L"Necromancy"},
    {SpellSchool_Transmutation, L"Transmutation"},
    {SpellSchool_Wands, L"Wands"},
    {SpellSchool_InnateAttack, L"Innate Attack"},
    {SpellSchool_BreathWeapon, L"Breath Weapon"},
    {SpellSchoolType(0), NULL}
};
