#include "Map.h"
class Campaign
{
	private:
		Map** maps;
		string title;
		int size;
	public:
		Campaign(Map** maps, int size);
		/**
		 * Method which tells the game which map to start on
		 * 
		 * \return the starting map of the campaign
		 */
		Map* Start();
		/**
		 * Method which loads the next map in the campaign.
		 * 
		 * \param i current index
		 * \return the next map after i
		 */
		Map* LoadAfter(int i);

		void RemoveMap(int i);

		// Getters and Setters for the title attribute
		string GetTitle();
		void SetTitle(string title);

		// Getters and Setters for the size attribute
		int GetSize();
		void SetSize(int size);



};

