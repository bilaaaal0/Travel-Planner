#include <iostream>

#include <vector>

#include <stdlib.h>

#include <cctype>

#include <string>

#include<math.h>

#include <conio.h>

#include<iomanip>

using namespace std;

class edge {
    public: 
	int in_node,
    ter_node,
    weight,
    distance,
    time;
    edge(int in , int ter, int dis, int time) {
        in_node = in;
        ter_node = ter;
        distance = dis;
        this -> time = time;
        weight = (distance / 15) * 250;
    }
};


class Hotel {
    public: string name;
    float distance; //from mid of the city
    float rating;
    int cost;
    int days;

    Hotel() {}
    Hotel(string name, float dis, float rating, int cost) {
        this -> name = name;
        this -> distance = dis;
        this -> rating = rating;
        this -> cost = cost;
        days = 0;
    }

};
class Spot {
    public: string name;
    float distance; //from mid of the city
    float rating;

    Spot() {}
    Spot(string name, float dis, float rating) {
        this -> name = name;
        this -> distance = dis;
        this -> rating = rating;
    }
    void display() {
        const int width = 15; 

        
        cout << "+" << setfill('-') << setw(width * 2) << "+" << endl;


        cout << setfill(' ');


        cout << "|" << left << setw(width) << "Name" << ": " << setw(width) << name << "|" << endl;  
        cout << "|" << left << setw(width) << "Distance" << ": " << setw(width) << distance << "|" << endl;
        cout << "|" << left << setw(width) << "Rating" << ": " << setw(width) << rating << "|" << endl;


        cout << "+" << setfill('-') << setw(width * 2) << "+" << endl;
    }
};
class Vertex {
    public: int city_id;
    string city_name;
    vector < edge > edges;
    vector < Hotel > hotels;
    vector < Spot > spots;
    Hotel yourPlanHotel;  //addplan hotels are saved here
    Vertex() {}

    Vertex(int id, string name): city_id(id),
    city_name(name) {}
    void add_edge(int ter, int dis, int time) {
        edge temp(city_id, ter, dis, time);
        edges.push_back(temp);
    }
    void addHotel() 
    {
        string name;
        float dis;
        float rating;
        int cost;
        cout << "Input hotel's name : ";
        cin >> name;
        cout << "Input hotel's cost per night : ";
        cin >> cost;
        cout << "Input hotel's distance from mid of city : ";
        cin >> dis;
        cout << "Input hotel's rating : ";
        cin >> rating;
        Hotel add(name, dis, rating, cost);
        hotels.push_back(add);
    }
    void addSpot() 
    {
        string name;
        float dis;
        float rating;
        int cost;
        cout << "Input spot's name : ";
        cin >> name;
        cout << "Input spot's distance from mid of city : ";
        cin >> dis;
        cout << "Input spot's rating : ";
        cin >> rating;
        Spot add(name, dis, rating);
        spots.push_back(add);

    }
    //merge sort for hotel rating
    void MergeSort(vector < Hotel > & s, int lb, int ub, vector < Hotel > & s2) {

        if (lb < ub) {
            int c = (lb + ub) / 2;
            MergeSort(s, lb, c, s2);
            MergeSort(s, c + 1, ub, s2);

            int i = lb;
            int j = c + 1;
            int k = lb;

            while (i <= c && j <= ub) {
                if (s[i].rating >= s[j].rating) {
                    s2[k] = s[i];
                    i++;
                } else {
                    s2[k] = s[j];
                    j++;
                }
                k++;
            }

            while (i <= c) {
                s2[k] = s[i];
                i++;
                k++;
            }

            while (j <= ub) {
                s2[k] = s[j];
                j++;
                k++;
            }

            for (int x = lb; x <= ub; x++) {
                s[x] = s2[x];
            }
        }
    }
    //merge sort for hotel cost
    void MergeSort2(vector < Hotel > & s, int lb, int ub, vector < Hotel > & s2) {

        if (lb < ub) {
            int c = (lb + ub) / 2;
            MergeSort2(s, lb, c, s2);
            MergeSort2(s, c + 1, ub, s2);

            int i = lb;
            int j = c + 1;
            int k = lb;

            while (i <= c && j <= ub) {
                if (s[i].cost <= s[j].cost) {
                    s2[k] = s[i];
                    i++;
                } else {
                    s2[k] = s[j];
                    j++;
                }
                k++;
            }

            while (i <= c) {
                s2[k] = s[i];
                i++;
                k++;
            }

            while (j <= ub) {
                s2[k] = s[j];
                j++;
                k++;
            }

            for (int x = lb; x <= ub; x++) {
                s[x] = s2[x];
            }
        }
    } // for hotel distance
    void MergeSort3(vector < Hotel > & s, int lb, int ub, vector < Hotel > & s2) {

        if (lb < ub) {
            int c = (lb + ub) / 2;
            MergeSort3(s, lb, c, s2);
            MergeSort3(s, c + 1, ub, s2);

            int i = lb;
            int j = c + 1;
            int k = lb;

            while (i <= c && j <= ub) {
                if (s[i].distance <= s[j].distance) {
                    s2[k] = s[i];
                    i++;
                } else {
                    s2[k] = s[j];
                    j++;
                }
                k++;
            }

            while (i <= c) {
                s2[k] = s[i];
                i++;
                k++;
            }

            while (j <= ub) {
                s2[k] = s[j];
                j++;
                k++;
            }

            for (int x = lb; x <= ub; x++) {
                s[x] = s2[x];
            }
        }
    }
    //sort spots by rating
    void MergeSort4(vector < Spot > & s, int lb, int ub, vector < Spot > & s2) {
        if (lb < ub) {
            int c = (lb + ub) / 2;
            MergeSort4(s, lb, c, s2);
            MergeSort4(s, c + 1, ub, s2);

            int i = lb;
            int j = c + 1;
            int k = lb;

            while (i <= c && j <= ub) {
                if (s[i].rating >= s[j].rating) {
                    s2[k] = s[i];
                    i++;
                } else {
                    s2[k] = s[j];
                    j++;
                }
                k++;
            }

            while (i <= c) {
                s2[k] = s[i];
                i++;
                k++;
            }

            while (j <= ub) {
                s2[k] = s[j];
                j++;
                k++;
            }

            for (int x = lb; x <= ub; x++) {
                s[x] = s2[x];
            }
        }
    }
    void SortSpotByRating() {
        vector < Spot > s;
        vector < Spot > s2;

        for (int i = 0; i < spots.size(); ++i) {
            s.push_back(spots[i]);
            s2.push_back(spots[i]);
        }
        MergeSort4(s, 0, s.size() - 1, s2);
        DisplaySpots(s, 1);
    }
    void SortHotelByRating() {
        vector < Hotel > h;
        vector < Hotel > h2;

        for (int i = 0; i < hotels.size(); ++i) {
            h.push_back(hotels[i]);
            h2.push_back(hotels[i]);
        }
        MergeSort(h, 0, h.size() - 1, h2);
        DisplayHotel(h, 1);
    }
    void SortHotelByCost() {
        vector < Hotel > h3;
        vector < Hotel > h4;

        for (int i = 0; i < hotels.size(); ++i) {
            h3.push_back(hotels[i]);
            h4.push_back(hotels[i]);
        }
        MergeSort2(h3, 0, h3.size() - 1, h4);
        DisplayHotel(h3, 2);
    }
    void SortHotelByDistance() {
        vector < Hotel > h5;
        vector < Hotel > h6;

        for (int i = 0; i < hotels.size(); ++i) {
            h5.push_back(hotels[i]);
            h6.push_back(hotels[i]);
        }
        MergeSort3(h5, 0, h5.size() - 1, h6);
        DisplayHotel(h5, 3);
    }
    void DisplayHotel(vector < Hotel > h, int a) {
        if (a == 1) {
            cout << "Sort by Rating (More to less)\n";
            cout << "__________\n";
        } else if (a == 2) {
            cout << "Sort by Cost (Less to more)\n";
            cout << "__________\n";
        } else {
            cout << "Sort by Distance (Less to more)\n";
            cout << "___________\n";
        }

        cout << left << setw(30) << "Name" << setw(10) << "Distance(in km)" << setw(15) << "Rating" << setw(10) << "Cost(in Rs.)" << endl;
        cout << setfill('-') << setw(50) << "" << setfill(' ') << endl; // This creates a line of dashes
        for (int i = 0; i < h.size(); ++i) {
            cout << left << setw(30) << h[i].name << setw(10) << h[i].distance << setw(15) << h[i].rating << setw(10) << h[i].cost << endl;
        }
    }
    void DisplaySpots(vector < Spot > s, int a) {
        cout << "SPOTS\n";
        cout << "========\n\n";
        
        cout << "Name\t\t\tRating\t\tDistance(in km)\n";
        for (int i = 0; i < s.size(); ++i) {
            cout << s[i].name << "\t\t\t" << s[i].rating << "\t\t" << s[i].distance << endl;
        }
    }
    void print(vector < Vertex > vertices) {
        if (edges.empty()) {
            cout << "No connections";
        } else {
            for (int i = 0; i < edges.size(); i++) {
                if (i > 0) cout << setw(30) << ""; 
                cout << "---> " << left << setw(20) << vertices[edges[i].ter_node].city_name; 
                cout << "Cost: " << left << setw(10) << edges[i].weight;
                cout << "Distance(in km): " << left << setw(10) << edges[i].distance;
                cout << "Time(in hours): " << left << setw(10) << edges[i].time << endl;
            }
        }
    }
    void displayHotels(Vertex * v1) {
        cout << "\nCity's Name: " << v1 -> city_name << "\n";
        cout << "Hotels in " << v1 -> city_name << ":\n";

        cout << left << setw(30) << "S.NO" << setw(30) << "Name" << setw(20) << "Distance(km)" << setw(20) << "Rating" << setw(20) << "Cost(in Rs)" << endl;
        cout << setfill('-') << setw(50) << "" << setfill(' ') << endl; // This creates a line of dashes
        for (int j = 0; j < v1 -> hotels.size(); ++j) {
            cout << left << setw(30) << j + 1 << setw(30) << v1 -> hotels[j].name << setw(20) << v1 -> hotels[j].distance << setw(20) << v1 -> hotels[j].rating << setw(20) << v1 -> hotels[j].cost << endl;
        }
    }

};

void convertDateToValue(const string & date, int result[]) 
{
    int multiplier = 10;
    int ind = 0;
    for (int i = 0; i < date.length(); ++i) 
	{
        if (date[i] == '-') 
		{
            ind++;
        } 
		else 
		{
            result[ind] = (date[i] - '0' + ((result[ind]) * multiplier));

        }
    }

}
bool checkDate(const string & date1,const string & date2) //queue
{
	int arr1[3];
	int arr2[3];
	for(int i=0;i<3;++i)
	{
		arr1[i] = 0;
		arr2[i] = 0;
	}
    convertDateToValue(date1, arr1);
    convertDateToValue(date2, arr2);

    
    int d1 = arr1[2] * 10000 + arr1[1] * 100 + arr1[0];
    int d2 = arr2[2] * 10000 + arr2[1] * 100 + arr2[0];

    return (d2>=d1);
}

bool compareDates(const string & date1,const string & mid,const string & date2, int arr1[], int arrMid[], int arr2[]) //agent avail
{

    convertDateToValue(date1, arr1);
    convertDateToValue(mid, arrMid);
    convertDateToValue(date2, arr2);


    int d1 = arr1[2] * 10000 + arr1[1] * 100 + arr1[0];
    int dateMid = arrMid[2] * 10000 + arrMid[1] * 100 + arrMid[0];
    int d2 = arr2[2] * 10000 + arr2[1] * 100 + arr2[0];

    return (d1 <= dateMid && dateMid <= d2);
}

class Agent 
{
    public: 
	string name;
    string password;
    string email;
    float rating;
    int charges;
    string * fromdate;
    string * todate;
    int index;
    public: Agent() 
	{
        index = 0;
        name = "-";
        password = "-";
        email = "-";
        rating = 0.0;
        charges = 0;
        fromdate = new string[1];
        fromdate[0] = "0";
        todate = new string[1];
        todate[0] = "0";
    }
    Agent(string n, string e, float r, int c, string password) {
        index = 0;
        name = n;
        email = e;
        rating = r;
        charges = c;
        fromdate = new string[10];
        todate = new string[10];
        for (int i = 0; i < 10; ++i) {
            fromdate[i] = "0";
            todate[i] = "0";
        }
        this -> password = password;
    }
    void display() {

        for (int i = 0; i < index; ++i)

        {
            cout << endl << endl;
            cout << fromdate[i];
            cout << todate[i];
            cout << endl << endl;
        }
    }
    void setFT(string f, string t) {
        fromdate[index] = f;
        todate[index] = t;
        index++;
    }
    bool available(string req) {
        bool flag = true;
        int a[3];
        int b[3];
        int c[3];
        for (int i = 0; i < 3; ++i) {
            a[i] = 0;
            b[i] = 0;
            c[i] = 0;
        }
        for (int i = 0; i < index; ++i) {
            if (compareDates(fromdate[i], req, todate[i], a, b, c)) {
                flag = false;
                break;
            }
        }
        return flag;

    }
    void initialize(vector < Agent > & Ag) {
        Agent bilal("Bilal", "1am@gmail.com", 9.5, 50000, "FAST123");
        Agent aadil("Aadil", "IRMID2@gmail.com", 7.0, 90000, "FAST123");
        Agent uzain("Uzain", "DSLABMID@gmail.com", 9.9, 100000, "FAST123");
        Ag.push_back(bilal);
        Ag.push_back(aadil);
        Ag.push_back(uzain);
    }
    void displayDetails() {
        cout << "\t\t\tAgentDetails\n";
        cout << "\t\t\t____________\n\n";
        const int field_width = 15;
        cout << left << setw(field_width) << "Name" << setw(field_width + 10) << "Email" << setw(field_width) << "Rating" << setw(field_width) << "Cost(in Rs)" << endl << endl;
        cout << left << setw(field_width) << name << setw(field_width + 10) << email << setw(field_width) << rating << setw(field_width) << charges << endl;
    }

};

class Customer {
    public: string name;
    string address;
    string email;
    string phoneNo;

    Customer() {}

    Customer(string name, string address, string email, string phoneNo) {
        this -> name = name;
        this -> address = address;
        this -> email = email;
        this -> phoneNo = phoneNo;
    }

    void displayInfo() {
        const int field_width = 15;
        cout << "\t\t\tCustomer Details\n";
        cout << "\t\t\t________________\n\n";
        cout << left << setw(field_width) << "Name" << setw(field_width) << "Address" << setw(field_width) << "Email" << setw(field_width) << "Phone Number" << endl;
        cout << left << setw(field_width) << name << setw(field_width) << address << setw(field_width) << email << setw(field_width) << phoneNo << endl;
    }

};

class graph {
    public: int count;
    vector < Vertex > vertices;
    vector < int > predecessor;
    vector < int > copy;
    vector < string > city_paths;
    vector < string > best_city_paths;
    vector < int > path_costs;
    vector < int > best_city_path_costs;
    int pathCost;
    int min = INT_MAX;
    int total;
    //vertex *v;
    graph() {
        total = 0;
        pathCost = 0;
        count = 0;
    }

    void perm(const vector < int > & v, int src) {
        city_paths.clear();
        total = 0;
        int flag = 0;
        path_costs.clear();

        dijkstra(src, v[0]);
        if (pathCost != INT_MAX) {

            path_costs.push_back(pathCost);
            total = total + pathCost;
            //cout<<total<<endl;
            for (int i = 0; i < v.size() - 1; ++i) {
                dijkstra(v[i], v[i + 1]);
                if (pathCost == INT_MAX) {
                    flag = 1;
                    break;
                }
                total = total + pathCost;
                path_costs.push_back(pathCost);
            }
            if (flag == 0) {

                //	cout<<endl;
                //cout<<"TOTAL"<<total<<endl<<endl;

                if (total < min) {
                    copy.clear();
                    best_city_paths.clear();
                    for (int i = 0; i < city_paths.size(); ++i) {
                        best_city_paths.push_back(city_paths[i]);
                    }
                    min = total;
                    copy.push_back(src);
                    for (int i = 0; i < v.size(); ++i) {

                        copy.push_back(v[i]);
                    }
                    best_city_path_costs.clear();
                    for (int i = 0; i < path_costs.size(); ++i) {
                        best_city_path_costs.push_back(path_costs[i]);
                    }
                }
            }

        }
    }
    void generate_city_permutations(vector < int > & v, int start_index, int end_index, int src) {
        if (start_index == end_index) {
             perm(v, src);
        } else {
            for (int i = start_index; i <= end_index; i++) {
                swap(v[start_index], v[i]);
                generate_city_permutations(v, start_index + 1, end_index, src);
                swap(v[start_index], v[i]);

            }
        }
    }
    void preplanned_path(vector < Vertex * > cities) {
        vector < int > destinations;

        for (int i = 0; i < cities.size(); ++i) {
            destinations.push_back(cities[i] -> city_id);

        }
        int src;
        redo6:
            this -> DisplayCity();
        cout << "\nChoose your Source City \n";
        cin >> src;
        if (src > 9) {
            goto redo6;
        }
        pathCost = 0;
        min = INT_MAX;
        total = 0;
        generate_city_permutations(destinations, 0, destinations.size() - 1, src);
    }

    void add_vertex(int id, string name) {
        ++count;
        vertices.push_back(Vertex(id, name)); 
    }

    void add_edge(int initial, int terminal, int distance, int time) {

        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i].city_id == initial) {
                vertices[i].add_edge(terminal, distance, time);
                break; 
            }
        }

        
        for (int j = 0; j < vertices.size(); j++) {
            if (vertices[j].city_id == terminal) {
                vertices[j].add_edge(initial, distance, time);
                break; 
            }
        }
    }

    void traverse_graph() {
        cout << left << setw(30) << "City Name"; 
        cout << left << setw(20) << "Connection" << "Cost(in Rs)\t\t" << setw(10) << "Distance(in km)\t\t" << setw(10) << "Time" << endl;
        cout << setfill('-') << setw(80) << "" << setfill(' ') << endl; 

        for (int i = 0; i < vertices.size(); i++) {
            cout << left << setw(30) << vertices[i].city_name;
            vertices[i].print(vertices);
            cout << endl;
        }
    }
    int min_distance(const vector < int > & dist,
        const vector < bool > & sptSet) {
        int min = INT_MAX, min_index = -1;

        for (size_t v = 0; v < vertices.size(); v++) {
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v], min_index = v;
            }
        }

        return min_index;
    }

    void search(int id) {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i].city_id == id) {
                cout << "\nCity's Name: " << vertices[i].city_name << "\n";
                cout << "Hotels in " << vertices[i].city_name << ":\n";
               
                cout << left << setw(30) << "Name" << setw(10) << "Distance(km)" << setw(15) << "Rating" << setw(15) << "Cost(Rs)" << endl;
                cout << setfill('-') << setw(50) << "" << setfill(' ') << endl; 
                for (int j = 0; j < vertices[i].hotels.size(); ++j) {
                    cout << left << setw(30) << vertices[i].hotels[j].name << setw(10) << vertices[i].hotels[j].distance << setw(15) << vertices[i].hotels[j].rating << setw(15) << vertices[i].hotels[j].cost << endl;
                }
                cout << "\nSpots in " << vertices[i].city_name << ":\n";
                cout << left << setw(30) << "Name" << setw(10) << "Rating" << setw(10) << "Distance(km)" << endl;
                cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
                for (int k = 0; k < vertices[i].spots.size(); ++k) {
                    cout << left << setw(30) << vertices[i].spots[k].name << setw(10) << vertices[i].spots[k].rating << setw(10) << vertices[i].spots[k].distance << endl;
                }
            }
        }
    }

    void dijkstra(int src, int dest, int flag = 0) {
        vector < int > dist(vertices.size(), INT_MAX);
        vector < bool > sptSet(vertices.size(), false);
        predecessor.resize(vertices.size(), -1);

        dist[src] = 0;

        for (size_t count = 0; count < vertices.size() - 1; count++) {
            int u = min_distance(dist, sptSet);
            sptSet[u] = true;

            for (size_t i = 0; i < vertices[u].edges.size(); i++) {
                edge & e = vertices[u].edges[i];
                if (!sptSet[e.ter_node] && dist[u] != INT_MAX && dist[u] + e.weight < dist[e.ter_node]) {
                    dist[e.ter_node] = dist[u] + e.weight;
                    predecessor[e.ter_node] = u; 
                }
            }
        }
        pathCost = dist[dest];
        if (flag == 0)
            path(dest);
        if (flag == 1)
            print_solution(dist, src, dest);
    }
    void path(int j) {
        if (predecessor[j] == -1) {
            Vertex * v = get_vertex_by_id(j);
            if (v)
                city_paths.push_back(v -> city_name);
            return;
        }
        path(predecessor[j]);
        Vertex * v = get_vertex_by_id(j);
        if (v)
            city_paths.push_back(v -> city_name);
        predecessor.clear();

    }

    Vertex * get_vertex_by_id(int city_id) {
        for (size_t i = 0; i < vertices.size(); i++) {
            if (vertices[i].city_id == city_id) {
                return & vertices[i];
            }
        }
        return NULL;
    }

    void print_path(int j) {
        if (predecessor[j] == -1) {
            Vertex * v = get_vertex_by_id(j);

            if (v) cout << v -> city_name << " ";
            return;
        }
        print_path(predecessor[j]);
        Vertex * v = get_vertex_by_id(j);
        if (v) cout << " -> " << v -> city_name << " ";
    }

    void print_solution(const vector < int > & dist, int src, int dest) {
        string src_city = get_vertex_by_id(src) -> city_name;
        string dest_city = get_vertex_by_id(dest) -> city_name;

        cout << "\nShortest Path from " << src_city << " to " << dest_city << ":\n";
        cout << string(50, '-') << endl;

        if (dist[dest] != INT_MAX) {
            cout << "Total Weight : " << dist[dest] << endl;
            cout << "Path: ";
            print_path(dest);
            predecessor.clear();
            cout << "\n" << string(50, '-') << endl;
        } else {

            cout << "No path exists from " << src_city << " to " << dest_city << "\n";
            cout << string(50, '-') << endl;
        }
    }

    Vertex * get_vertex_by_name(const string & name) {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i].city_name == name) {
                return & vertices[i];
            }
        }
        return NULL;
    }
    Vertex * ToADDHotelSpot(int id) {
        bool check = false;
        int i = 0;
        for (i = 0; i < vertices.size(); ++i) {
            if (id == vertices[i].city_id) {
                check = true;

                break;
            }
        }
        if (check) {
            return & vertices[i];
        } else {
            cout << "No city exist with ID : " << id << endl;
            return NULL;

        }
    }

    void DisplayCity() {
        int nameWidth = 30;
        cout << left << setw(nameWidth) << "Name" << "ID" << endl;
        cout << setfill('-') << setw(nameWidth) << "" << setfill(' ') << '-' << endl;
        for (int i = 0; i < vertices.size(); ++i) {
            cout << left << setw(nameWidth) << vertices[i].city_name << vertices[i].city_id << endl;
        }
    }

    void initialize(graph & pak) {
     
        pak.add_vertex(0, "Karachi");
        pak.add_vertex(1, "Multan");
        pak.add_vertex(2, "Lahore");
        pak.add_vertex(3, "Faisalabad");
        pak.add_vertex(4, "Islamabad");
        pak.add_vertex(5, "Quetta");
        pak.add_vertex(6, "Peshawar");
        pak.add_vertex(7, "Chitral");
        pak.add_vertex(8, "Skardu");
        pak.add_vertex(9, "Gilgit");


        pak.add_edge(0, 1, 923, 18);
        pak.add_edge(1, 2, 350, 7);
        pak.add_edge(2, 3, 196, 3);
        pak.add_edge(3, 4, 256, 5);
        pak.add_edge(4, 5, 342, 6); 
        pak.add_edge(5, 6, 599, 12);
        pak.add_edge(6, 7, 325, 6);
        pak.add_edge(7, 8, 359, 7);
        pak.add_edge(8, 9, 208, 4);



        pak.add_edge(0, 4, 1430, 22); // Karachi to Islamabad (made-up values)
        pak.add_edge(1, 4, 546, 10); // Multan to Islamabad
        pak.add_edge(2, 4, 396, 7); // Lahore to Islamabad
        pak.add_edge(5, 4, 863, 16); // Quetta to Islamabad (made-up values)
        pak.add_edge(6, 4, 186, 3); // Peshawar to Islamabad
        pak.add_edge(7, 4, 439, 8); // Chitral to Islamabad
        pak.add_edge(9, 4, 470, 9); // Gilgit to Islamabad

      
        pak.add_edge(0, 2, 1265, 25); // Karachi to Lahore
        pak.add_edge(2, 6, 524, 10); // Lahore to Peshawar
        pak.add_edge(3, 6, 324, 6); // Faisalabad to Peshawar
        pak.add_edge(6, 9, 574, 11); // Peshawar to Gilgit
        pak.add_edge(7, 9, 228, 4); // Chitral to Gilgit

        Hotel h("marriot hotel", 23, 4.5, 9000);
        pak.vertices[0].hotels.push_back(h);
        Hotel h1("Pearl Continental", 34, 4.3, 11000);
        pak.vertices[0].hotels.push_back(h1);
        Hotel h2("Ramada Plaza", 19, 4.7, 15000);
        pak.vertices[0].hotels.push_back(h2);
        Hotel h3("Regent Plaza", 20, 4, 7000);
        pak.vertices[1].hotels.push_back(h3);

        Hotel h4("Serena Hotel", 28, 4.2, 8500);
        pak.vertices[1].hotels.push_back(h4);

        Hotel h5("Fortalice Multan", 22, 4.6, 12000);
        pak.vertices[1].hotels.push_back(h5);

        Hotel h6("Ramada Multan", 18, 4.4, 11000);
        pak.vertices[1].hotels.push_back(h6);


        Hotel h7("Avari Lahore", 30, 4.8, 13000);
        pak.vertices[2].hotels.push_back(h7);

        Hotel h8("Hospitality Inn Lahore", 25, 4.1, 9500);
        pak.vertices[2].hotels.push_back(h8);

        Hotel h9("Movenpick Hotel Lahore", 35, 4.5, 16000);
        pak.vertices[2].hotels.push_back(h9);


        Hotel h10("Fiesta Inn Faisalabad", 26, 4.3, 10000);
        pak.vertices[3].hotels.push_back(h10);

        Hotel h11("Faisalabad Serena Hotel", 29, 4.6, 12000);
        pak.vertices[3].hotels.push_back(h11);

        Hotel h12("Garvaish Luxury Hotel", 24, 4.2, 9000);
        pak.vertices[3].hotels.push_back(h12);

     
        Hotel h13("Islamabad Serena Hotel", 32, 4.9, 18000);
        pak.vertices[4].hotels.push_back(h13);

        Hotel h14("Islamabad Marriott Hotel", 36, 4.7, 15000);
        pak.vertices[4].hotels.push_back(h14);

        Hotel h15("Pearl Continental Islamabad", 33, 4.4, 13000);
        pak.vertices[4].hotels.push_back(h15);

    
        Hotel h16("Quetta Serena Hotel", 21, 4.0, 7000);
        pak.vertices[5].hotels.push_back(h16);

        Hotel h17("Quetta International Hotel", 27, 4.5, 9500);
        pak.vertices[5].hotels.push_back(h17);

        Hotel h18("Quetta Residency", 23, 4.1, 8000);
        pak.vertices[5].hotels.push_back(h18);


        Hotel h19("Pearl Continental Peshawar", 31, 4.6, 14000);
        pak.vertices[6].hotels.push_back(h19);

        Hotel h20("Pearl Continental Peshawar", 29, 4.3, 12000);
        pak.vertices[6].hotels.push_back(h20);

        Hotel h21("Pearl Continental Peshawar", 25, 4.5, 13000);
        pak.vertices[6].hotels.push_back(h21);


        Hotel h22("Chitral Serena Hotel", 18, 4.2, 9000);
        pak.vertices[7].hotels.push_back(h22);

        Hotel h23("Hindukush Heights Hotel", 20, 4.4, 11000);
        pak.vertices[7].hotels.push_back(h23);

        Hotel h24("Chitral Inn", 16, 4.0, 8000);
        pak.vertices[7].hotels.push_back(h24);


        Hotel h25("Shangrila Resort Skardu", 30, 4.7, 16000);
        pak.vertices[8].hotels.push_back(h25);

        Hotel h26("Concordia Motel Skardu", 24, 4.3, 13000);
        pak.vertices[8].hotels.push_back(h26);

        Hotel h27("Skardu Continental Hotel", 26, 4.5, 14000);
        pak.vertices[8].hotels.push_back(h27);


        Hotel h28("Gilgit Serena Hotel", 22, 4.6, 12000);
        pak.vertices[9].hotels.push_back(h28);

        Hotel h29("Gilgit Baltistan Inn", 19, 4.2, 10000);
        pak.vertices[9].hotels.push_back(h29);

        Hotel h30("Hunza View Hotel", 25, 4.5, 13000);
        pak.vertices[9].hotels.push_back(h30);

        Spot s1("Clifton Beach", 25, 4.8);
        pak.vertices[0].spots.push_back(s1);

        Spot s2("Dolmen Mall", 22, 4.5);
        pak.vertices[0].spots.push_back(s2);

        Spot s3("Pakistan Maritime Museum", 20, 4.3);
        pak.vertices[0].spots.push_back(s3);


        Spot s4("Shahi Eidgah", 28, 4.2);
        pak.vertices[1].spots.push_back(s4);

        Spot s5("Multan Fort", 24, 4.6);
        pak.vertices[1].spots.push_back(s5);

        Spot s6("Bahauddin Zakariya University", 18, 4.4);
        pak.vertices[1].spots.push_back(s6);

 
        Spot s7("Badshahi Mosque", 30, 4.9);
        pak.vertices[2].spots.push_back(s7);

        Spot s8("Lahore Fort", 25, 4.8);
        pak.vertices[2].spots.push_back(s8);

        Spot s9("Shalimar Gardens", 35, 4.7);
        pak.vertices[2].spots.push_back(s9);


        Spot s10("Gatwala Wildlife Park", 26, 4.3);
        pak.vertices[3].spots.push_back(s10);

        Spot s11("Lyallpur Museum", 29, 4.6);
        pak.vertices[3].spots.push_back(s11);

        Spot s12("Jinnah Garden", 24, 4.2);
        pak.vertices[3].spots.push_back(s12);


        Spot s13("Faisal Mosque", 32, 4.9);
        pak.vertices[4].spots.push_back(s13);

        Spot s14("Pakistan Monument", 36, 4.7);
        pak.vertices[4].spots.push_back(s14);

        Spot s15("Lok Virsa Museum", 33, 4.4);
        pak.vertices[4].spots.push_back(s15);


        Spot s16("Hanna Lake", 21, 4.0);
        pak.vertices[5].spots.push_back(s16);

        Spot s17("Quetta Geological Museum", 27, 4.5);
        pak.vertices[5].spots.push_back(s17);

        Spot s18("Hazarganji Chiltan National Park", 23, 4.1);
        pak.vertices[5].spots.push_back(s18);


        Spot s19("Peshawar Museum", 31, 4.6);
        pak.vertices[6].spots.push_back(s19);

        Spot s20("Qissa Khwani Bazaar", 29, 4.3);
        pak.vertices[6].spots.push_back(s20);

        Spot s21("Bala Hisar Fort", 25, 4.5);
        pak.vertices[6].spots.push_back(s21);

        Spot s22("Chitral Gol National Park", 18, 4.2);
        pak.vertices[7].spots.push_back(s22);

        Spot s23("Shahi Mosque Chitral", 20, 4.4);
        pak.vertices[7].spots.push_back(s23);

        Spot s24("Kalasha Valleys", 16, 4.0);
        pak.vertices[7].spots.push_back(s24);

        Spot s25("Shangrila Resort", 30, 4.7);
        pak.vertices[8].spots.push_back(s25);

        Spot s26("Shigar Fort", 24, 4.3);
        pak.vertices[8].spots.push_back(s26);

        Spot s27("Deosai National Park", 26, 4.5);
        pak.vertices[8].spots.push_back(s27);


        Spot s28("Naltar Valley", 22, 4.6);
        pak.vertices[9].spots.push_back(s28);

        Spot s29("Rakaposhi View Point", 19, 4.2);
        pak.vertices[9].spots.push_back(s29);

        Spot s30("Kargah Buddha", 25, 4.5);
        pak.vertices[9].spots.push_back(s30);
    }

};

class Plan {
    public: string name_of_plan;
    int cost;
    int no_of_days;
    vector < Vertex * > cities;
    Plan * P1;
    Plan() {
        name_of_plan = "NONE";
        no_of_days = 5;
    }

    Plan * ViewPlans(graph & pak) { 
        int numPlans = 7;
        P1 = new Plan[numPlans];

    
        P1[0].name_of_plan = "Punjabi Dream";
        P1[0].cost = 12250 + 107000;
        P1[0].no_of_days = 7;
        P1[0].cities.push_back(pak.get_vertex_by_id(2)); // Lahore
        P1[0].cities.push_back(pak.get_vertex_by_id(4)); // Islamabad
        P1[0].cities.push_back(pak.get_vertex_by_id(1)); // Multan

        P1[1].name_of_plan = "Winter Special";
        P1[1].cost = 7000 + 123000;
        P1[1].no_of_days = 8;
        P1[1].cities.push_back(pak.get_vertex_by_id(7)); // Chitral
        P1[1].cities.push_back(pak.get_vertex_by_id(9)); // Gilgit
        P1[1].cities.push_back(pak.get_vertex_by_id(8)); // Skardu

        P1[2].name_of_plan = "Pak Tour";
        P1[2].cost = 38000 + 197000;
        P1[2].no_of_days = 8;
        P1[2].cities.push_back(pak.get_vertex_by_id(0)); // Karachi
        P1[2].cities.push_back(pak.get_vertex_by_id(2)); // Lahore
        P1[2].cities.push_back(pak.get_vertex_by_id(4)); // Islamabad
        P1[2].cities.push_back(pak.get_vertex_by_id(5)); // Quetta
        P1[2].cities.push_back(pak.get_vertex_by_id(6)); // Peshawar

        P1[3].name_of_plan = "The Big Three";
        P1[3].cost = 28000 + 120000;
        P1[3].no_of_days = 6;
        P1[3].cities.push_back(pak.get_vertex_by_id(0)); // Karachi
        P1[3].cities.push_back(pak.get_vertex_by_id(4)); // Islamabad
        P1[3].cities.push_back(pak.get_vertex_by_id(2)); // Lahore

        P1[4].name_of_plan = "Among the Mountains";
        P1[4].cost = 19750 + 144000;
        P1[4].no_of_days = 6;
        P1[4].cities.push_back(pak.get_vertex_by_id(5)); // Quetta
        P1[4].cities.push_back(pak.get_vertex_by_id(8)); // Skardu
        P1[4].cities.push_back(pak.get_vertex_by_id(7)); // Chitral
        P1[4].cities.push_back(pak.get_vertex_by_id(9)); // Gilgit

        P1[5].name_of_plan = "Lower Regions";
        P1[5].cost = 24250 + 106000;
        P1[5].no_of_days = 6;
        P1[5].cities.push_back(pak.get_vertex_by_id(0)); // Karachi 
        P1[5].cities.push_back(pak.get_vertex_by_id(3)); // Faisalabad
        P1[5].cities.push_back(pak.get_vertex_by_id(2)); // Lahore

        P1[6].name_of_plan = "The Whole Of Pak";
        P1[6].cost = 55000 + 360000;
        P1[6].no_of_days = 30;
        P1[6].cities.push_back(pak.get_vertex_by_id(0)); // Karachi
        P1[6].cities.push_back(pak.get_vertex_by_id(5)); // Quetta
        P1[6].cities.push_back(pak.get_vertex_by_id(3)); // Faisalabad
        P1[6].cities.push_back(pak.get_vertex_by_id(2)); // Lahore
        P1[6].cities.push_back(pak.get_vertex_by_id(4)); // Islamabad
        P1[6].cities.push_back(pak.get_vertex_by_id(6)); // Peshawar
        P1[6].cities.push_back(pak.get_vertex_by_id(8)); // Skardu
        P1[6].cities.push_back(pak.get_vertex_by_id(7)); // Chitral
        P1[6].cities.push_back(pak.get_vertex_by_id(9)); // Gilgit

        system("cls");
        cout << "\n\n\n \t\t\t\t\t\t Viewing Plans\n";
        cout << "       \t\t\t\t\t\t ______\n";
        cout << "       \t\t\t\t\t\t ______\n\n";
        cout << right << "S.No" << setw(20) << "Plan Name" << setw(20) << "Cost(Rs)" << setw(13) << "Days" << setw(25) << "Cities" << endl << endl;

        for (int i = 0; i < numPlans; i++) {
            cout << (i + 1);
            cout << setw(25) << P1[i].name_of_plan;
            cout << setw(18) << P1[i].cost;
            cout << setw(10) << P1[i].no_of_days << "                ";

            for (int j = 0; j < P1[i].cities.size(); j++) {
                cout << P1[i].cities[j] -> city_name;
                if (j < P1[i].cities.size() - 1) {
                    cout << " -> ";
                }
            }
            cout << endl << endl;
        }

        return P1;
    }
};
class Node {
    public:

        Customer cus;
    string date;
    Plan plan;
    vector < string > path;
    int peopleCount;
    Agent A;
    Node * next;
    int pathcost;
    vector < int > best_city_path_costs;
    vector < int > IDs;

    int ID;
    Node() {
        next = NULL;
        peopleCount = 0;
    }

    Node(Customer & c, string & d, int p, Plan & pl, Agent & a, int ID, vector < string > & path, int pathcost, vector < int > x, vector < int > IDs) {
        next = NULL;
        date = d;
        cus = c;
        peopleCount = p;
        plan = pl;
        A = a;
        this -> ID = ID;
        this -> path = path;
        this -> pathcost = pathcost;
        best_city_path_costs = x;
        this -> IDs = IDs;
    }
    Node(Customer & c, string & d, int p, Plan & pl, int ID, vector < string > & path, int pathcost, vector < int > x, vector < int > IDs) {
        next = NULL;
        date = d;
        cus = c;
        peopleCount = p;
        plan = pl;
        this -> ID = ID;
        this -> path = path;
        this -> pathcost = pathcost;
        best_city_path_costs = x;
        this -> IDs = IDs;
    }
};
double roundToNearest(double value, int factor = 1000) {
    return round(value / factor) * factor;
}
class LastBooking {
    public: Node * top;
    LastBooking() {
        top = NULL;
    }
    void AddLastBooking(Node * n) {
        top = n;

    }
    void Pop() {
        top = NULL;
    }
    void Display(graph pak) {
        system("cls");
        const int id_width = 10;
        const int customer_width = 15;
        const int date_width = 20;
        const int plan_width = 20;
        const int agent_width = 20;
        const int people_width = 7;
        int hotel_total = 0;
        if (top != NULL) {
            cout << "\t\t\tBooking Receipt\n";
            cout << "\t\t\t_______________\n";
            cout << "\t\t\t_______________\n\n\n";

            // Display Customer Details
            top -> cus.displayInfo();
            cout << endl << endl;
            top -> A.displayDetails();
            cout << endl << endl;
            cout << "\t\t\tBooking Details\n";
            cout << "\t\t\t_______________\n\n";
            cout << left << setw(id_width) << "Booking ID  " <<
                setw(customer_width) << "Customer" <<
                setw(date_width) << "Date" <<
                setw(plan_width) << "Plan" <<
                setw(agent_width) << "Agent" <<
                setw(people_width) << "People" << endl;
            cout << string(100, '-') << endl;
            cout << left << setw(id_width) << top -> ID <<
                setw(customer_width) << top -> cus.name <<
                setw(date_width) << top -> date <<
                setw(plan_width) << top -> plan.name_of_plan <<
                setw(agent_width) << top -> A.name <<
                setw(people_width) << top -> peopleCount << endl;

            cout << endl;
            cout << "\nPath : ";
            for (int i = 0; i < top -> path.size(); ++i) {
                if (i == 0) {
                    cout << top -> path[i] << " ";
                } else if (top -> path[i] != top -> path[i - 1]) {
                    cout << "->" << top -> path[i] << " ";
                }
            }
            cout << "\nTotal Path cost " << top -> pathcost << endl;;
            cout << "\nCity Sequence and Costs\n";
            cout << left << setw(15) << "City ID" <<
                left << setw(20) << "City Name" <<
                left << "Cost to Next City" << endl;
            cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
            for (int i = 0; i < top -> IDs.size(); ++i) {
                cout << left << setw(15) << top -> IDs[i] <<
                    left << setw(20) << pak.vertices[top -> IDs[i]].city_name;
                if (i < top -> best_city_path_costs.size()) {
                    cout << left << top -> best_city_path_costs[i];
                }
                cout << endl;
            }
            int a = roundToNearest(top -> pathcost);
            //cout << "\nTravelling Cost : " << a <<" Rs"<< endl;

            if (top -> plan.name_of_plan == "NONE") {
                cout << "\nHOTELS\n";

                cout << left << setw(20) << "City Name" <<
                    setw(30) << "Hotel Name" <<
                    setw(20) << "Rating" <<
                    setw(20) << "Cost(Rs)" <<
                    setw(20) << "Days of Stay" <<
                    endl;

                cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;

                for (int i = 0; i < top -> plan.cities.size(); ++i) {
                    cout << left << setw(20) << top -> plan.cities[i] -> city_name <<
                        setw(30) << top -> plan.cities[i] -> yourPlanHotel.name <<
                        setw(20) << top -> plan.cities[i] -> yourPlanHotel.rating <<
                        setw(20) << top -> plan.cities[i] -> yourPlanHotel.cost <<
                        setw(20) << top -> plan.cities[i] -> yourPlanHotel.days <<
                        endl;
                    hotel_total = hotel_total + (top -> plan.cities[i] -> yourPlanHotel.cost * top -> plan.cities[i] -> yourPlanHotel.days);
                }
                cout << "\n\n\tCost(Rs)\n\n";
                int b = roundToNearest(hotel_total);
                int c = roundToNearest(top -> A.charges);
                cout << "\nTravelling cost : " << a << " Rs";
                cout << "\nHotel Cost :" << b << " Rs";
                cout << "\n\nAgent Cost : " << c << " Rs";
                //cout << "\nTotal Cost of trip per person : Rs " << hotel_total + top->pathcost + top->A.charges<<endl;
                float temp = top -> peopleCount;
                if (temp >= 2.0)
                    temp = temp / 2.0;
                temp = ceil(temp);

                cout << "\nFor Total of trip of " << top -> peopleCount << " people : Rs " << (temp * a) + (temp * b) + c;
            } else {
                cout << "\nHOTELS\n";
                cout << left << setw(20) << "City Name" <<
                    setw(30) << "Hotel Name" <<
                    setw(20) << "Rating" <<
                    setw(20) << "Cost(Rs)" <<
                    setw(20) << "Days of Stay" <<
                    endl;

                cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;

                for (int i = 0; i < top -> plan.cities.size(); ++i) {
                    cout << left << setw(20) << top -> plan.cities[i] -> city_name <<
                        setw(30) << top -> plan.cities[i] -> hotels[0].name <<
                        setw(20) << top -> plan.cities[i] -> hotels[0].rating <<
                        setw(20) << top -> plan.cities[i] -> hotels[0].cost <<
                        setw(20) << top -> plan.cities[i] -> hotels[0].days <<
                        endl;
                    hotel_total = hotel_total + (top -> plan.cities[i] -> hotels[0].cost * top -> plan.cities[i] -> hotels[0].days);
                }
                cout << endl; 
                cout << "\n\n\t\tCost(Rs)\n\n";

                int b = roundToNearest(hotel_total);
                int c = roundToNearest(top -> A.charges);
                cout << "\n\nTravelling cost : " << a << " Rs";
                cout << "\n\nHotel Cost : " << b << " Rs";
                cout << "\n\nAgent Cost : " << c << " Rs";
                float temp = top -> peopleCount;

                if (temp >= 2.0)
                    temp = temp / 2.0;
                temp = ceil(temp);
                cout << "\nFor Total of trip of " << top -> peopleCount << " people : Rs " << (temp * a) + (temp * b) + c;
            }
        } else {
            cout << "No booking information available." << endl;
        }
    }
};
class BookingQueue {
    public: Node * front;
    Node * rear;
    LastBooking lb;
    BookingQueue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL && rear == NULL);
    }
    void Display(BookingQueue b1, graph pak) {
        system("cls");
        const int id_width = 10;
        const int customer_width = 15;
        const int date_width = 20;
        const int plan_width = 20;
        const int agent_width = 20;
        const int people_width = 7;
        int hotel_total = 0;
        Node * top = b1.front;
        int c = 1;
        while (top != NULL) {
            cout << "\t\t\tBooking Receipt " << c << "\n";
            cout << "\t\t\t_______________\n";
            cout << "\t\t\t_______________\n\n\n";
            c++;
            // Display Customer Details
            top -> cus.displayInfo();
            cout << endl << endl;
            top -> A.displayDetails();
            cout << endl << endl;
            cout << "\t\t\tBooking Details\n";
            cout << "\t\t\t_______________\n\n";
            cout << left << setw(id_width) << "Booking ID  " <<
                setw(customer_width) << "Customer" <<
                setw(date_width) << "Date" <<
                setw(plan_width) << "Plan" <<
                setw(agent_width) << "Agent" <<
                setw(people_width) << "People" << endl;
            cout << string(70, '-') << endl;
            cout << left << setw(id_width) << top -> ID <<
                setw(customer_width) << top -> cus.name <<
                setw(date_width) << top -> date <<
                setw(plan_width) << top -> plan.name_of_plan <<
                setw(agent_width) << top -> A.name <<
                setw(people_width) << top -> peopleCount << endl;

            cout << endl;
            cout << "\nPath : ";
            for (int i = 0; i < top -> path.size(); ++i) {
                if (i == 0) {
                    cout << top -> path[i] << " ";
                } else if (top -> path[i] != top -> path[i - 1]) {
                    cout << "->" << top -> path[i] << " ";
                }
            }
            cout << "\nTotal Path cost " << top -> pathcost << endl;;
            cout << "\nCity Sequence and Costs\n";
            cout << left << setw(15) << "City ID" <<
                left << setw(20) << "City Name" <<
                left << "Cost to Next City" << endl;
            cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
            for (int i = 0; i < top -> IDs.size(); ++i) {
                cout << left << setw(15) << top -> IDs[i] <<
                    left << setw(20) << pak.vertices[top -> IDs[i]].city_name;
                if (i < top -> best_city_path_costs.size()) {
                    cout << left << top -> best_city_path_costs[i];
                }
                cout << endl;
            }
            int a = roundToNearest(top -> pathcost);
            //cout << "\nTravelling Cost : " << a <<" Rs"<< endl;

            if (top -> plan.name_of_plan == "NONE") {
                cout << "\nHOTELS\n";

                cout << left << setw(20) << "City Name" <<
                    setw(30) << "Hotel Name" <<
                    setw(20) << "Rating" <<
                    setw(20) << "Cost(Rs)" <<
                    setw(20) << "Days of Stay" <<
                    endl;

                cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;

                for (int i = 0; i < top -> plan.cities.size(); ++i) {
                    cout << left << setw(20) << top -> plan.cities[i] -> city_name <<
                        setw(30) << top -> plan.cities[i] -> yourPlanHotel.name <<
                        setw(20) << top -> plan.cities[i] -> yourPlanHotel.rating <<
                        setw(20) << top -> plan.cities[i] -> yourPlanHotel.cost <<
                        setw(20) << top -> plan.cities[i] -> yourPlanHotel.days <<
                        endl;
                    hotel_total = hotel_total + (top -> plan.cities[i] -> yourPlanHotel.cost * top -> plan.cities[i] -> yourPlanHotel.days);
                }
                cout << "\n\n\tCost(Rs)\n\n";
                int b = roundToNearest(hotel_total);
                int c = roundToNearest(top -> A.charges);
                cout << "\nTravelling cost : " << a << " Rs";
                cout << "\nHotel Cost :" << b << " Rs";
                cout << "\n\nAgent Cost : " << c << " Rs";
                //cout << "\nTotal Cost of trip per person : Rs " << hotel_total + top->pathcost + top->A.charges<<endl;
                float temp = top -> peopleCount;
                if (temp >= 2.0)
                    temp = temp / 2.0;
                temp = ceil(temp);
                cout << "\nFor Total of trip of " << top -> peopleCount << " people : Rs " << (temp * a) + (temp * b) + c;
            } else {
                cout << "\nHOTELS\n";
                cout << left << setw(20) << "City Name" <<
                    setw(30) << "Hotel Name" <<
                    setw(20) << "Rating" <<
                    setw(20) << "Cost(Rs)" <<
                    setw(20) << "Days of Stay" <<
                    endl;

                cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;

                for (int i = 0; i < top -> plan.cities.size(); ++i) {
                    cout << left << setw(20) << top -> plan.cities[i] -> city_name <<
                        setw(30) << top -> plan.cities[i] -> hotels[0].name <<
                        setw(20) << top -> plan.cities[i] -> hotels[0].rating <<
                        setw(20) << top -> plan.cities[i] -> hotels[0].cost <<
                        setw(20) << top -> plan.cities[i] -> hotels[0].days <<
                        endl;
                    hotel_total = hotel_total + (top -> plan.cities[i] -> hotels[0].cost * top -> plan.cities[i] -> hotels[0].days);
                }
                cout << endl; 
                cout << "\n\n\t\tCost(Rs)\n\n";

                int b = roundToNearest(hotel_total);
                int c = roundToNearest(top -> A.charges);
                cout << "\n\nTravelling cost : " << a << " Rs";
                cout << "\n\nHotel Cost : " << b << " Rs";
                cout << "\n\nAgent Cost : " << c << " Rs";
                float temp = top -> peopleCount;
                if (temp >= 2.0)
                    temp = temp / 2.0;
                temp = ceil(temp);

                cout << "\nFor Total of trip of " << top -> peopleCount << " people : Rs " << (temp * a) + (temp * b) + c;
            }
            top = top -> next;
            cout << endl << endl;
        }
    }

    void enqueue(Node * n) {
        if (isEmpty()) {
            front = n;
            rear = n;

        } else {
            Node * ptr = front;
            Node * prev = NULL;
            bool flag = false;
            while (ptr != NULL) {
                if (!checkDate(ptr -> date, n -> date)) {
                    flag = true;
                    break;
                }
                prev = ptr;
                ptr = ptr -> next;
            }
            if (prev == NULL && flag) {
                n -> next = front;
                front = n;
            } else if (flag) {
                prev -> next = n;
                n -> next = ptr;
            } else {
                rear -> next = n;
                rear = n;
            }
        }
    }

    Node * dequeue() {
        Node * temp = NULL;
        if (isEmpty()) {
            cout << "No booking\n" << endl;
            return NULL;
        } else {
            if (front == rear) {
                temp = front;
                front = NULL;
                rear = NULL;
                return temp;
            } else {
                temp = front;
                front = front -> next;
                return temp;
            }
        }
    }

    int count() {
        int count = 0;
        Node * temp = front;
        while (temp != NULL) {
            count++;
            temp = temp -> next;
        }
        return count;
    }

    void display() {
        if (isEmpty()) {
            cout << "No Booking\n" << endl;
        } else {
            cout << left << setw(35) << "Name" << setw(35) << "Email" << setw(15) << "Date" << setw(10) << "People" << setw(10) << "Amount(Rs)" << endl << endl;
            Node * temp = front;
            while (temp != NULL) {
                cout << left << setw(35) << temp -> cus.name <<
                    setw(35) << temp -> cus.email <<
                    setw(15) << temp -> date <<
                    setw(10) << temp -> peopleCount <<
                    setw(10) << temp -> plan.cost << endl;
                temp = temp -> next;
            }
            cout << endl;
        }
    }

    void AddBooking(Customer c, string d, int peo, Plan p, Agent & a, int ID, vector < string > path, int pathcost, vector < int > costs, vector < int > IDs) {
        Node * n = new Node(c, d, peo, p, a, ID, path, pathcost, costs, IDs);
        enqueue(n);
        lb.AddLastBooking(n);

    }

    void printBooking() {
        display();
    }
};
void addDaysToDate(string & date, int daysToAdd) {
    int day, month, year;
    sscanf(date.c_str(), "%d-%d-%d", & day, & month, & year);

    day += daysToAdd;

    while (day > 31) {
        day -= 31;
        month++;

        while (month > 12) {
            month -= 12;
            year++;
        }
    }


    char buffer[9];
    sprintf(buffer, "%02d-%02d-%02d", day, month, year % 100);
    date = buffer;
}

void display_menu() {
    const int width = 80; 
    cout << setw(width) << setfill('=') << "" << endl; 
    cout << setfill(' '); 

    cout << "\nPlease choose an option from below:\n\n";
    cout << setw(4) << "1" << setw(2) << "-" << " Manage the Map" << endl;
    cout << setw(6) << "" << "Includes adding cities, connecting them with roads, and setting up the map.\n";

    cout << setw(4) << "2" << setw(2) << "-" << " Utilize the Map" << endl;
    cout << setw(6) << "" << "Allows displaying the graph, finding the shortest path between cities," << endl;
    cout << setw(6) << "" << "adding tourist spots or hotels to a city, and searching within a city.\n";

    cout << setw(4) << "3" << setw(2) << "-" << " View all cities" << endl;

    cout << setw(4) << "4" << setw(2) << "-" << " View all plans" << endl;

 
    cout << setw(4) << "5" << setw(2) << "-" << " View all Bookings" << endl;
    cout << setw(4) << "6" << setw(2) << "-" << " View Hotels(Sorted Order)" << endl;
    cout << setw(4) << "7" << setw(2) << "-" << " View Spots" << endl;
    cout << setw(4) << "8" << setw(2) << "-" << " Back to Main Menu" << endl;

    cout << setw(width) << setfill('=') << "" << endl; 
    cout << setfill(' '); 
}

void display_welcome_message() {
    const int box_width = 70; 
    const int screen_width = 80; 
    const int left_padding = (screen_width - box_width) / 2; 

    cout << "\n\n"; 
    cout << setw(left_padding) << "" << setw(box_width) << setfill('*') << "" << endl; 
    cout << setfill(' '); 

    cout << setw(left_padding) << "\t" << "* Welcome to the FAST NUCES Travel Planner application.    \t" << endl << endl << endl << endl;
    cout << setw(left_padding) << "\t\t" << "* This program will assist you in planning      \t" << endl << endl << endl << endl;
    cout << setw(left_padding) << "\t\t" << "* your trip by providing information on the     \t" << endl << endl << endl << endl;
    cout << setw(left_padding) << "\t\t" << "* shortest routes, hotel recommendations,       \t" << endl << endl << endl << endl;
    cout << setw(left_padding) << "\t\t" << "* and estimated costs for your journey.         \t" << endl << endl << endl << endl;
    cout << setw(left_padding) << "\t\t" << "* Let's get started on planning your adventure! \t" << endl << endl << endl;

    cout << setw(left_padding) << "" << setw(box_width) << setfill('*') << "" << endl;
    cout << setfill(' '); 
    cout << endl << endl;
    cout << "Press 1 to Proceed, Press 0 to exit\n";
}
void thankYouMessage() {
    const int box_width = 70; 
    const int screen_width = 80; 
    const int left_padding = (screen_width - box_width) / 2;

    cout << "\n\n"; 
    cout << setw(left_padding) << "" << setw(box_width) << setfill('*') << "" << endl; 
    cout << setfill(' '); 

    cout << "\t\tThank you for using our travel planning program!\n";
    cout << "\t\tWe hope your journey is filled with joy, adventure,\n";
    cout << "\t\tand unforgettable memories.\n\n";

    cout << "\t\tSafe travels and see you again on your next adventure!\n\n";

}
bool CheckForCity(int arr[], int size, int check) {
    bool flag = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == check) {
            flag = true;
            break;
        }
    }
    return flag;
}

int main() {
    graph pak;
    Plan x;
    Agent AG;
    BookingQueue bookings;
    vector < Agent > Ag;
    pak.initialize(pak);
    AG.initialize(Ag);
    int B_ID = -1;
    int role = -1;
    string city_name, username, password;
    bool accessGranted = false;
    int vertices, edges;
    int v, e, d, t, src, dest, choice;
    system("color 70");
    do {
        system("cls");
        display_welcome_message();
        cin >> choice;
        if (choice == 0) {
            thankYouMessage();
            return 0;
        } else if (choice == 1) {

            system("cls");
            cout << "\t\t\t\t\t\t FAST Travel Planner\n\n\n";
            label1:

                cout << "Are you a (1)'admin' or an (2)'customer'? Enter your role: ";
            accessGranted = false;
            cin >> role;
            if (role == 1) {
                do {
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;

                    if (username == Ag[0].name && password == Ag[0].password || username == Ag[1].name && password == Ag[1].password || username == Ag[2].name && password == Ag[2].password) {
                        cout << "Access granted.\nWelcome agent " << username << endl;
                        accessGranted = true;
                    } else {
                        cout << "Incorrect username or password." << endl;
                        char tryAgain;
                        cout << "Do you want to try again? (y/n): ";
                        cin >> tryAgain;
                        if (tryAgain == 'n' || tryAgain == 'N') {
                            cout << "Exiting admin login.\n\n" << endl;
                            goto label1;
                        } else continue;
                    }
                } while (!accessGranted);

                label2:
                    redo9:
                    display_menu();
                cout << "Your choice: ";
                cin >> choice;
                if (choice > 8) {
                    goto redo9;
                }
                if (choice == 1) {

                    cout << "Enter the number of cities: ";
                    cin >> vertices;
                    int x = pak.count;
                    for (int i = pak.count; i < x + vertices; ++i) {
                        cout << "Enter name for city ID:" << i << ": ";
                        cin >> city_name;
                        pak.add_vertex(i, city_name);
                    }

                    cout << "Enter the number of roads (edges): ";
                    cin >> edges;
                    pak.DisplayCity();
                    cout << "Enter the roads in the format: StartCityID EndCityID Distance Time" << endl;
                    for (int i = 0; i < edges; ++i) {
                        cin >> v >> e >> d >> t;
                        pak.add_edge(v, e, d, t);
                    }
                    getch();
                    goto label2;
                } else if (choice == 2) {
                    redo13: cout << "Enter '1' to display the graph\n";
                    cout << "Enter '2' to find the shortest path using Dijkstra's algorithm\n";
                    cout << "Enter '3' to add spot or hotel in a city\n";
                    cout << "Enter '4' to search hotels and spots in a city\n";
                    cout << "Input choice : ";
                    cin >> choice;
                    if (choice > 4) {
                        goto redo13;
                    }
                    if (choice == 1) {
                        pak.traverse_graph();
                        getch();
                        goto label2;
                    } else if (choice == 2) {
                        int source_id, dest_id;
                        redo15:
                            pak.DisplayCity();
                        cout << "Enter the source city ID for Dijkstra's algorithm: ";
                        cin >> source_id;
                        if (source_id > (pak.vertices.size() - 1)) {
                            goto redo15;
                        }
                        cout << "Enter the destination city ID: ";
                        cin >> dest_id;
                        if (dest_id > 9) {
                            goto redo15;
                        }
                        pak.dijkstra(source_id, dest_id, 1);
                        getch();
                        goto label2;
                    } else if (choice == 3) {
                        redo20: cout << "Add hotel and spot in cities\n\n";
                        pak.DisplayCity();
                        cout << "Input city ID : ";
                        int id;
                        cin >> id;
                        if (id > (pak.vertices.size() - 1)) {
                            goto redo20;
                        }
                        Vertex * v1 = pak.ToADDHotelSpot(id);
                        if (v1 != NULL) {
                            int c;
                            redo50:
                                cout << "Input '1' to add hotel or '2' to add spot : ";
                            cin >> c;
                            if (c > 2) {
                                goto redo50;
                            }
                            if (c == 1) {

                                v1 -> addHotel();
                                v1 -> displayHotels(v1);
                            } else if (c == 2) {
                                v1 -> addSpot();

                            }
                        }
                        getch();
                        goto label2;
                    }
                    else if (choice == 4) {
                        int id;
                        redo30:
                            pak.DisplayCity();
                        cout << "Enter city id";
                        cin >> id;
                        if (id > (pak.vertices.size() - 1)) {
                            goto redo30;
                        }
                        pak.search(id);
                        getch();
                        goto label2;
                    } else {
                        cout << "Invalid choice. Exiting program." << endl;
                    }
                }
                else if (choice == 3) {

                    pak.DisplayCity();
                    getch();
                    goto label2;
                } else if (choice == 6) {
                    redo53: pak.DisplayCity();
                    cout << "Input city ID : ";
                    int id;
                    cin >> id;
                    if (id > (pak.vertices.size() - 1)) {
                        goto redo53;
                    }
                    Vertex * v1 = pak.ToADDHotelSpot(id);
                    v1 -> SortHotelByDistance();
                    v1 -> SortHotelByCost();
                    v1 -> SortHotelByRating();
                    getch();
                    goto label2;

                }
                else if (choice == 5) {
                    bookings.Display(bookings, pak);
                    getch();
                    goto label2;
                } else if (choice == 4) {
                    Plan p;
                    p.ViewPlans(pak);
                    getch();
                    goto label2;
                } else if (choice == 7) {
                    int id;
                    redo60:
                        pak.DisplayCity();
                    cout << "Enter city id";
                    cin >> id;
                    if (id > (pak.vertices.size() - 1)) {
                        goto redo60;
                    }
                    for (int i = 0; i < pak.vertices[id].spots.size(); ++i) {
                        pak.vertices[id].spots[i].display();
                    }
                    getch();
                    goto label2;
                } else if (choice == 8) {
                    goto label1;
                }

            } else if (role == 2) {
                redo55: cout << "\nInput '1' to view plans and '2' to add your own plan : ";

                cin >> choice;
                if (choice > 2 || choice < 1) {
                    goto redo55;
                }
                Plan p;
                Plan * P;
                int sn = -1;
                int num_destinations;
                if (choice == 1) {

                    P = p.ViewPlans(pak);
                    hehe:
                        cout << "\n\nInput S.No of plan you want to select : ";

                    cin >> sn;
                    if (sn > 7 || sn < 1) {
                        cout << "plan not available choose again\n";
                        goto hehe;
                    }
                    //system("cls");
                    cout << "You selected " << P[sn - 1].name_of_plan << "\n";
                    int q = sn - 1;
                    if (q == 0) {
                        P[0].cities[0] -> hotels[0].days = 2;
                        P[0].cities[1] -> hotels[0].days = 3;
                        P[0].cities[2] -> hotels[0].days = 2;

                    } else if (q == 1) {
                        P[1].cities[0] -> hotels[0].days = 2;
                        P[1].cities[1] -> hotels[0].days = 3;
                        P[1].cities[2] -> hotels[0].days = 3;

                    } else if (q == 2) {
                        P[2].cities[0] -> hotels[0].days = 2;
                        P[2].cities[1] -> hotels[0].days = 2;
                        P[2].cities[2] -> hotels[0].days = 2;
                        P[2].cities[3] -> hotels[0].days = 1;
                        P[2].cities[3] -> hotels[0].days = 1;

                    } else if (q == 3) {
                        P[3].cities[0] -> hotels[0].days = 2;
                        P[3].cities[1] -> hotels[0].days = 2;
                        P[3].cities[2] -> hotels[0].days = 2;
                    } else if (q == 4) {
                        P[4].cities[0] -> hotels[0].days = 2;
                        P[4].cities[1] -> hotels[0].days = 1;
                        P[4].cities[2] -> hotels[0].days = 1;
                        P[4].cities[3] -> hotels[0].days = 2;
                    } else if (q == 5) {
                        P[5].cities[0] -> hotels[0].days = 2;
                        P[5].cities[1] -> hotels[0].days = 2;
                        P[5].cities[2] -> hotels[0].days = 2;

                    } else if (q == 6) {
                        P[6].cities[0] -> hotels[0].days = 3;
                        P[6].cities[1] -> hotels[0].days = 3;
                        P[6].cities[2] -> hotels[0].days = 4;
                        P[6].cities[3] -> hotels[0].days = 3;
                        P[6].cities[4] -> hotels[0].days = 3;
                        P[6].cities[5] -> hotels[0].days = 4;
                        P[6].cities[6] -> hotels[0].days = 3;
                        P[6].cities[7] -> hotels[0].days = 3;
                        P[6].cities[8] -> hotels[0].days = 4;
                    }

                } else if (choice == 2) {
                    pak.DisplayCity();
                    string city_name;
                    int src;
                    int dest;

                    redo1:
                        cout << "Enter the source city ID: ";
                    cin >> src;
                    if (src > (pak.vertices.size() - 1)) {
                        goto redo1;
                    }

                    redo2:
                        cout << "Enter the number of destinations: ";
                    cin >> num_destinations;
                    if (num_destinations > (pak.vertices.size() - 1)) {
                        goto redo2;
                    }

                    vector < int > destinations;

                    int arr[num_destinations];
                    for (int i = 0; i < num_destinations; ++i) {
                        arr[i] = -1;
                    }
                    Vertex v;
                    // Loop to get destinations
                    x.cities.clear();
                    for (int i = 0; i < num_destinations; ++i) {
                        WrongCity: redo3: cout << "Enter destination city ID #" << (i + 1) << " : ";

                        cin >> dest;
                        if (dest > 9) {
                            goto redo3;
                        }
                        if (CheckForCity(arr, num_destinations, dest)) {
                            cout << "This city is already selected in your plan. Please select different cities\n";
                            goto WrongCity;
                        }

                        arr[i] = dest;
                        destinations.push_back(dest);

                        x.cities.push_back(pak.get_vertex_by_id(dest));
                        v.displayHotels(pak.get_vertex_by_id(dest));
                        redo4: cout << "\nInput S.No to select hotel : ";
                        int hello;
                        cin >> hello;
                        if (hello > 3) {
                            goto redo4;
                        }
                        Hotel h = x.cities[i] -> hotels[hello - 1];

                        cout << "\nInput number of days to stay in this hotel : ";
                        int daysss;
                        cin >> daysss;
                        x.no_of_days += daysss;
                        h.days = daysss;
                        x.cities[i] -> yourPlanHotel = h;
                    }
                    pak.pathCost = 0;
                    pak.min = INT_MAX;
                    pak.total = 0;
                    pak.generate_city_permutations(destinations, 0, destinations.size() - 1, src);
                    destinations.clear();

                }

                const int box_width = 50;
                string name,
                email,
                date,
                address,
                contact;
                int people;
                cout << setw(box_width) << setfill('=') << "" << endl;
                cout << setfill(' ');
                cout << "Input name : ";
                cin.ignore();
                getline(cin, name);
                cout << "Input email : ";
                getline(cin, email);
                cout << "Input address : ";
                getline(cin, address);
                cout << "Input contact(num) : ";
                getline(cin, contact);
                cout << "Input number of person : ";
                cin >> people;
                cout << "Input date (dd-mm-yy) : ";
                cin >> date;
                cout << setw(box_width) << setfill('=') << "" << endl;
                cout << setfill(' ');

                string f = date;
                if (sn != -1)
                    addDaysToDate(f, P[sn - 1].no_of_days);
                if (sn == -1)
                    addDaysToDate(f, 5);
                const int name_width = 20;
                const int rating_width = 10;
                const int charges_width = 10;

                cout << left << setw(6) << "S.No" << setw(name_width) << "Name" << setw(rating_width) << "Rating" << setw(charges_width) << "Charges" << endl;
                cout << string(50, '-') << endl;
                bool flag = false;
                int y;
                for (int i = 0; i < Ag.size(); ++i) {
                    if (Ag[i].available(date) && Ag[i].available(f)) {
                        flag = true;
                        cout << left << setw(6) << i + 1 << setw(name_width) << Ag[i].name << setw(rating_width) << Ag[i].rating << setw(charges_width) << Ag[i].charges << endl;
                        //	Ag[i].display();
                        cout << endl;
                    }
                }
                if (!flag) {
                    cout << "There are no Agents available on " << date << endl;
                    y = 0;
                } else {
                    cout << "Input S.No to select agent or '0' to not : ";
                    redo:
                        cin >> y;
                    if (y > 3) {
                        cout << "agent not available choose again\n";
                        goto redo;
                    }
                }

                if (y != 0) {
                    Ag[y - 1].setFT(date, f);
                    Agent selected = Ag[y - 1];
                    Customer c(name, email, address, contact);
                    ++B_ID;
                    if (sn != -1) {

                        pak.preplanned_path(P[sn - 1].cities);
                        bookings.AddBooking(c, date, people, P[sn - 1], selected, B_ID, pak.best_city_paths, pak.min, pak.best_city_path_costs, pak.copy);
                    } else {
                        bookings.AddBooking(c, date, people, x, selected, B_ID, pak.best_city_paths, pak.min, pak.best_city_path_costs, pak.copy);
                    }
                } else {
                    Agent A;
                    Customer c(name, email, address, contact);
                    ++B_ID;
                    if (sn != -1) {

                        pak.preplanned_path(P[sn - 1].cities);
                        bookings.AddBooking(c, date, people, P[sn - 1], A, B_ID, pak.best_city_paths, pak.min, pak.best_city_path_costs, pak.copy);
                    } else {
                        bookings.AddBooking(c, date, people, x, A, B_ID, pak.best_city_paths, pak.min, pak.best_city_path_costs, pak.copy);
                    }
                }

                //bookings.Display(bookings,pak);
                bookings.lb.Display(pak);
                bookings.lb.Pop();
                int want;
                cout << "\n\nPress '1' to see the details of your plan : ";
                cin >> want;
                if (want) {
                    if (choice == 1) {
                        for (int i = 0; i < P[sn - 1].cities.size(); ++i) {
                            cout << "\t\t\tCity " << i + 1 << "\n";
                            cout << "\t\t\t__ " << endl << endl << endl;

                            // Print the hotel and spots information for the current city
                            cout << "Hotel to stay in " << P[sn - 1].cities[i] -> city_name << ":\n";
                            cout << P[sn - 1].cities[i] -> hotels[0].name << endl;

                            cout << "\nSpots to visit in " << P[sn - 1].cities[i] -> city_name << ":\n";
                            for (int j = 0; j < P[sn - 1].cities[i] -> spots.size(); ++j) {
                                cout << "- " << P[sn - 1].cities[i] -> spots[j].name << " (Rating: " << P[sn - 1].cities[i] -> spots[j].rating << ")\n";
                            }

                            cout << "\n";
                        }
                    } else if (choice == 2) {
                        for (int i = 0; i < x.cities.size(); ++i) {
                            cout << "\t\t\tCity " << i + 1 << "\n";
                            cout << "\t\t\t__ " << endl << endl << endl;

                            // Print the hotel and spots information for the current city
                            cout << "  Hotel to stay in " << x.cities[i] -> city_name << ":\n";
                            cout << "  " << x.cities[i] -> yourPlanHotel.name << endl;
                            cout << "  Number of day(s) to stay : " << x.cities[i] -> yourPlanHotel.days << endl;

                            cout << "\nSpots to visit in " << x.cities[i] -> city_name << ":\n";
                            for (int j = 0; j < x.cities[i] -> spots.size(); ++j) {
                                cout << "- " << x.cities[i] -> spots[j].name << " (Rating: " << x.cities[i] -> spots[j].rating << ")\n";
                            }

                            cout << "\n";
                        }
                    }
                }

            }
            else {
                cout << "wrong input ,try again\n";
                goto label1;
            }

        };

        getch();
    } while (1);
}
