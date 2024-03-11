#include "Map.h"
#ifndef CAMPAIGN
#define CAMPAIGN
using namespace std;
#include <vector>
class Campaign
{
	private:
		vector<Map*> maps;
		string title;
		int size;
	public:
		Campaign(vector<Map*> maps, string title, int size);
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

		void RemoveMap(int mapToRemove);
		void AddMap(Map* mapToAdd);

		// Getters and Setters for the title attribute
		string GetTitle();
		void SetTitle(string title);

		// Getters and Setters for the size attribute
		int GetSize();
		void SetSize(int size);

		string ToString();

		vector<Map> GetMaps();
		void SetMaps(vector<Map> maps);

		



};
#endif
