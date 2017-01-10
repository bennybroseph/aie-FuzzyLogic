#ifndef _UTILITYNPC_H_
#define _UTILITYNPC_H_
#pragma once

#include "src/World.h"
#include "src/BaseNPC.h"
#include "src/UtilityValue.h"
#include "src/UtilityScore.h"

#include <map>

namespace UtilitySystem
{
	class UtilityNPC : public BaseNPC
	{
	public:

		explicit UtilityNPC(World *pWorld);
		~UtilityNPC();

	protected:

		void selectAction(float a_fdeltaTime) override;

	private:

		UtilityValue m_waterValue;
		UtilityValue m_foodValue;
		UtilityValue m_restValue;
		UtilityValue m_logValue;

		std::map<std::string, UtilityScore *> m_pUtilityScoreMap;

	};
}
#endif // _UTILITYNPC_H_