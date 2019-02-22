#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;
 
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
 int playerCount,myId,zoneCount, edges;
    cin >> playerCount >> myId >> zoneCount >> edges;
    vector<int> vecZone[zoneCount];
    int platinumSourceCount[zoneCount];
    for (int i = 0; i < zoneCount; i++) {
     int a;
     cin >> a >> platinumSourceCount[a];
    }
    while (edges--) {
        int a, b;
        cin >> a >> b;
        vecZone[a].push_back(b);
        vecZone[b].push_back(a);
    }
    int ownerIds[zoneCount],podsP0[zoneCount],podsP1[zoneCount],visible[zoneCount],platinumSource[zoneCount],visited[zoneCount], totalPods ;
    while (true) {
        int myPlatinum, nTry, hqPos;
        nTry=0;
        cin >> myPlatinum;
        for (int i = 0; i < zoneCount; i++) {
            int zId;
            cin >> zId >> ownerIds[zId]>> podsP0[zId]>> podsP1[zId]>> visible[zId]>> platinumSource[zId];
        }
        if (ntry==0){
            for (int i = 0; i < zoneCount; i++) {
                if ((myId == 0 && podsP0[i] > 0) || myId == 1 && podsP1[i] > 0)
                    hqPos=i;
            }    
        }
        totalPods=0;
        for (int i = 0; i < zoneCount; i++) {
            if ((myId == 0 && podsP0[i] > 0) || myId == 1 && podsP1[i] > 0)
                totalPods++
        }
        for (int i = 0; i < (totalPods/6) -1; i++){
            // found the nearest pods to the hq and pods will protect the hq
            // to find pods nearest to hq using dp and link
            // and i under will be totalPods/6
        }
        for (int i = 0; i < zoneCount; i++) {
            if ((myId == 0 && podsP0[i] > 0) || myId == 1 && podsP1[i] > 0) {
                int next = -1;
                for (int nextId : vecZone[i]) {
                    if (ownerIds[nextId] != myId)
                        visited[nextId] = ownerIds[nextId] == -1 ? 0 : -1;
                    if (next == -1 || visited[nextId] < visited[next] || (visited[nextId] == 0 && platinumSource[nextId] > platinumSource[next]))
                        next = nextId;
                }
                visited[next] += 1 + (visited[next] == -1 ? 1 : 0);
                cout << (myId == 0 ? podsP0[i] : podsP1[i]) << " " << i << " " << next << " ";
            }
        }
        cout << endl << "WAIT" << endl;
    }
    nTry++
}
