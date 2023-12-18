class FoodRatings {
    map<string, pair<string, int>> foodToCuisineAndRating;
    map<string, map<int, set<string>>> cuisineToRatingAndFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodToCuisineAndRating[foods[i]]={cuisines[i],ratings[i]};
            cuisineToRatingAndFoods[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    void changeRating(string food, int newRating) {
        string cuisine=foodToCuisineAndRating[food].first;
        int rating=foodToCuisineAndRating[food].second;
        foodToCuisineAndRating[food]={cuisine,newRating};
        cuisineToRatingAndFoods[cuisine][rating].erase(food);
        if(cuisineToRatingAndFoods[cuisine][rating].size()==0){
            cuisineToRatingAndFoods[cuisine].erase(rating);
        }
        cuisineToRatingAndFoods[cuisine][newRating].insert(food);
    }

    string highestRated(string cuisine) {
        return *cuisineToRatingAndFoods[cuisine].rbegin()->second.begin();
    }
};