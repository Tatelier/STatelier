#pragma once

#include "SelectItem.h"

namespace Tatelier::SongSelect {
	class ScoreOverview;
	class ScoreSelectItem : public SelectItem {
	public:
		ScoreSelectItem(std::shared_ptr<ScoreOverview> item);

		virtual ~ScoreSelectItem() override;

	private:
		std::shared_ptr<ScoreOverview> item;

		// SelectItem ����Čp������܂���
		virtual SongSelectItemType GetType() override;
		virtual const std::string& GetMainTitle() override;

		// SelectItem ����Čp������܂���
		virtual std::shared_ptr<BackgroundInfo> GetBackgroundInfo() override;
	};

}
