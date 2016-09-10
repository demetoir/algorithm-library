



//https://www.acmicpc.net/problem/9008
//http://www.geeksforgeeks.org/given-a-set-of-line-segments-find-if-any-two-segments-intersect/
//http://geomalgorithms.com/a09-_intersect-3.html
//https://en.wikipedia.org/wiki/Bentley%E2%80%93Ottmann_algorithm

//좌표를 각각 축에 대해 정렬함
//각점에서 수직 수평 으로 가장 인접한 점끼리 이루는 선분을 만듦
//그래프 탐색을 해서 모든점을 거치고 시작점으로 돌아오는 경로 선분들을 
//교차하는지 판별한다
//여러개의 선분에서 교차 판별을 아직 모른다