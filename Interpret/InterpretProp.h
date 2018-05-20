#pragma once

std::wstring TagToString(ULONG ulPropTag, _In_opt_ LPMAPIPROP lpObj, bool bIsAB, bool bSingleLine);
std::wstring TypeToString(ULONG ulPropTag);
std::wstring ProblemArrayToString(_In_ const SPropProblemArray& problems);
std::wstring MAPIErrToString(ULONG ulFlags, _In_ const MAPIERROR& err);
std::wstring TnefProblemArrayToString(_In_ const STnefProblemArray& error);

struct NamePropNames
{
	std::wstring name;
	std::wstring guid;
	std::wstring dasl;
	std::wstring bestPidLid;
	std::wstring otherPidLid;
};

NamePropNames NameIDToStrings(
	ULONG ulPropTag, // optional 'original' prop tag
	_In_opt_ LPMAPIPROP lpMAPIProp, // optional source object
	_In_opt_ LPMAPINAMEID lpNameID, // optional named property information to avoid GetNamesFromIDs call
	_In_opt_ const _SBinary* lpMappingSignature, // optional mapping signature for object to speed named prop lookups
	bool bIsAB); // true if we know we're dealing with an address book property (they can be > 8000 and not named props)

std::wstring RestrictionToString(_In_ const _SRestriction* lpRes, _In_opt_ LPMAPIPROP lpObj);
std::wstring ActionsToString(_In_ const ACTIONS& actions);

std::wstring AdrListToString(_In_ const ADRLIST& adrList);

void InterpretProp(_In_ const _SPropValue* lpProp, _In_opt_ std::wstring* PropString, _In_opt_ std::wstring* AltPropString);