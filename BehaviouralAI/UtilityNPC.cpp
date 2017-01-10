#include "UtilityNPC.h"


namespace UtilitySystem
{
	UtilityNPC::UtilityNPC(World *pWorld) : BaseNPC(pWorld)
	{
		m_waterValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_waterValue.setMinMaxValues(0, 15);
		m_waterValue.setValue(getWaterValue());

		auto pWaterScore = new UtilityScore();
		pWaterScore->addUtilityValue(&m_waterValue, 2.f);
		m_pUtilityScoreMap["collectWater"] = pWaterScore;

		m_foodValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_foodValue.setMinMaxValues(0, 10);
		m_foodValue.setValue(getFoodValue());

		auto pFoodScore = new UtilityScore();
		pFoodScore->addUtilityValue(&m_foodValue, 1.f);
		m_pUtilityScoreMap["collectFood"] = pFoodScore;

		m_restValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_restValue.setMinMaxValues(0, 5);
		m_restValue.setValue(getRestValue());

		auto pRestScore = new UtilityScore();
		pRestScore->addUtilityValue(&m_restValue, 0.5f);
		m_pUtilityScoreMap["aquireRest"] = pRestScore;

		m_logValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_logValue.setMinMaxValues(0, 2);
		m_logValue.setValue(getNumberOfLogs());

		auto pLogScore = new UtilityScore();
		pLogScore->addUtilityValue(&m_logValue, 0.5f);
		m_pUtilityScoreMap["collectLog"] = pLogScore;
	}

	void UtilityNPC::selectAction(float a_fdeltaTime)
	{
		m_waterValue.setValue(getWaterValue());
		m_foodValue.setValue(getFoodValue());
		m_restValue.setValue(getRestValue());
		m_logValue.setValue(getNumberOfLogs());

		auto fBestScore = 0.f;
		std::string strBestAction;
		for (auto score : m_pUtilityScoreMap)
		{
			auto fThisScore = score.second->getUtilityScore();
			if (fThisScore > fBestScore)
			{
				fBestScore = fThisScore;
				strBestAction = score.first;
			}
		}

		if (strBestAction == "collectWater")
			collectWater(a_fdeltaTime);
		else if (strBestAction == "collectFood")
			collectFood(a_fdeltaTime);
		else if (strBestAction == "aquireRest")
			rest(a_fdeltaTime);
		else if (strBestAction == "collectLog")
			chopTree(a_fdeltaTime);
		else
			buildHouse(a_fdeltaTime);
	}

	UtilityNPC::~UtilityNPC() {	}
}
