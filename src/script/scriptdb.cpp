// Copyright (c) 2021 The DECENOMY Core Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "script/scriptdb.h"
#include "script/script.h"
#include "dbwrapper.h"

bool CScriptDB::WriteContract(const uint256 consensusScriptHash, const CScriptContract contract)
{
    // TODO: Maybe we should check script validity here before we write it to the database
    uint256 hash = contract.GetConsensusScriptHash(TYPE_X11KVS);
    return true; // Write(consensusScriptHash, contract);
}

bool CScriptDB::ReadContract(const uint256 consensusScriptHash, CScriptContract& contract)
{
    return true; // Read(consensusScriptHash, contract);
}

// TODO: Erasing Scripts from database can be dangerous so maybe it should just be marked as 'DISABLED' if this it's needed
// bool CScriptDB::EraseContract(CScriptContract& contract)
// {
//     return Erase(contract.GetConsensusScriptHash(contract, TYPE_X11KVS));
// }

bool CScriptDB::ContractExists(const CScriptContract& contract)
{
    uint256 hash = contract.GetConsensusScriptHash(TYPE_X11KVS);
    return true; // Exists(hash);
}

bool CScriptDB::UpdateContractStatus(uint256& consensusScriptHash, const bool status, CScriptContract& contract)
{
    if (!this->ReadContract(consensusScriptHash, contract))
    {
        LogPrintf("%s : ERROR: Failed to find the contract\n", __func__);
        return false;
    }

    contract.status = status;
    consensusScriptHash = contract.GetConsensusScriptHash(TYPE_X11KVS);
    return this->WriteContract(consensusScriptHash, contract);
}