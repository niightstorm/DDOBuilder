// RequiresOneOf.h
//
#pragma once
#include "XmlLib\DLMacros.h"

class Character;
class Feat;
class TrainedFeat;
class Requirement;

class RequiresOneOf :
    public XmlLib::SaxContentElement
{
    public:
        RequiresOneOf(void);
        void Write(XmlLib::SaxWriter * writer) const;

        bool CanTrainFeat(
                const Character & charData, 
                const std::vector<size_t> & classLevels,
                size_t totalLevel,
                const std::list<TrainedFeat> & currentFeats) const;
        bool CanTrainEnhancement(
                const Character & charData,
                size_t trainedRanks) const;
        bool CanTrainTree(
                const Character & charData) const;
        void CreateRequirementStrings(
                const Character & charData,
                std::vector<CString> * requirements,
                std::vector<bool> * met) const;

        bool VerifyObject(
                std::stringstream * ss,
                const std::list<Feat> & allFeats) const;

    protected:
        XmlLib::SaxContentElementInterface * StartElement(
                const XmlLib::SaxString & name,
                const XmlLib::SaxAttributes & attributes);

        virtual void EndElement();

        #define RequiresOneOf_PROPERTIES(_) \
                DL_OBJECT_LIST(_, Requirement, Requirements)

        DL_DECLARE_ACCESS(RequiresOneOf_PROPERTIES)
        DL_DECLARE_VARIABLES(RequiresOneOf_PROPERTIES)
};
