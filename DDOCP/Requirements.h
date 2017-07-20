// Requirements.h
//
#pragma once
#include "XmlLib\DLMacros.h"
#include "Requirement.h"
#include "RequiresNoneOf.h"
#include "RequiresOneOf.h"

class Character;
class EnhancementTree;
class Feat;
class TrainedFeat;

class Requirements :
    public XmlLib::SaxContentElement
{
    public:
        Requirements(void);
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
                const std::list<EnhancementTree> & allTrees,
                const std::list<Feat> & allFeats) const;
    protected:
        XmlLib::SaxContentElementInterface * StartElement(
                const XmlLib::SaxString & name,
                const XmlLib::SaxAttributes & attributes);

        virtual void EndElement();

        #define Requirements_PROPERTIES(_) \
                DL_OBJECT_LIST(_, Requirement, Requires) \
                DL_OPTIONAL_OBJECT(_, RequiresOneOf, OneOf) \
                DL_OPTIONAL_OBJECT(_, RequiresNoneOf, NoneOf)

        DL_DECLARE_ACCESS(Requirements_PROPERTIES)
        DL_DECLARE_VARIABLES(Requirements_PROPERTIES)

        friend class CEnhancementEditorDialog;
};