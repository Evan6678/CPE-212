#include "graph.h"

Graph::Graph()
{
  vertices = NULL;          //make an empty Vertex node
}

void Graph::AddVertex(string v)
{
  try
  {
    //if its the first node set next to NULL
    if (vertices == NULL)
    {
      vertices = new VertexNode;

      vertices -> vname = v;
      vertices -> mark = false;
      vertices -> edgePtr = NULL;
      vertices -> nextVertex = NULL;

    }//end if
    //if it is not the first node
    else
    {
      VertexNode* tempVertices;               //create temp value
      tempVertices = new VertexNode;          //create new VertexNode

      tempVertices -> vname = v;              //assign vname
      tempVertices -> mark = false;           //set the mark to default false
      tempVertices -> edgePtr = NULL;         //inits the edgePtr to NULL
      tempVertices -> nextVertex = vertices;  //set next by pointing back

      vertices = tempVertices;                //move vertices over
    }//end else
  }//end try
  catch(bad_alloc)
  {
    throw GraphFull();                        //catch full graph
  }//end catch
}//end AddVertex()

void Graph::AddEdge(string s, string d, int w)
{

	//############ Set the Variables step#############
	//create a temp var of VertexNode for source
	VertexNode* tempSource = vertices;
	//create a temp var of VertexNode for destination
	VertexNode* tempDestination = vertices;
	//create a temp new EdgeNode to hold the edge list
	EdgeNode* tempEdge;

	//test if full with try catch
  try
  {
		tempEdge = new EdgeNode;
  }
  catch(bad_alloc)
  {
    throw GraphFull();
  }

  //########## find the destination and set it#######
  //use a while loop to find the destination Vertex node
  while (tempDestination != NULL)
  {
    //if finds the node break loop
    if(tempDestination -> vname == d)
    {
      break;
    }

    tempDestination = tempDestination -> nextVertex;
  }

  //catch false NULL by leaving loop to early
  if(tempDestination == NULL)
  {
    throw GraphVertexNotFound();
  }

  //######## find the source and set values###########
  //use while loop to find the source vertex nodes
  while(tempSource != NULL)
  {
    //if finds the node break loop
    if(tempSource -> vname == s)
    {
      break;
    }

    tempSource = tempSource -> nextVertex;
  }

  //catch false NULL by leaving loop to early
  if (tempSource == NULL)
  {
    throw GraphVertexNotFound();
  }

  //######## set the nodes########################
  //set EdgeNode
  tempEdge -> weight = w;
  tempEdge -> destination = tempDestination;
  tempEdge -> nextEdge = tempSource -> edgePtr;

  //set vertexNode values
  tempSource -> edgePtr = tempEdge;

}

VertexNode* Graph::VertexExists(string v) const
{
  //create a temp var of VertexNode = verices
  VertexNode* tempVer = vertices;
  //find the vertices with the vname == v
  while (tempVer != NULL)
  {
    //if v == vname return the temp var
    if (tempVer -> vname == v)
    {
      return tempVer;
    }
    tempVer = tempVer -> nextVertex;
  }
  //if it reaches here then it reached NULL, return NULL
  return NULL;
}

EdgeNode* Graph::EdgeExists(string s, string d) const
{
  //create temp nodes for source and Edge
	VertexNode* tempSource = vertices;
	EdgeNode* tempEdge;
  //loop throught to find source nodes
	while(tempSource != NULL)
	{
		if(tempSource -> vname == s)
		{
			break;
		}

		tempSource = tempSource -> nextVertex;
	}
  //if source is not found return NULL
	if (tempSource == NULL)
	{
		return NULL;
	}

	//#### IF IT MADE IT HERE IT FOUND VALUE###
	//assign the tempEdge
	tempEdge = tempSource -> edgePtr;

  //if source is found loop through edge nodes to find tempDestination
	while(tempEdge != NULL)
	{
		if(tempEdge -> destination -> vname == d)
		{
			break;
		}

		tempEdge = tempEdge -> nextEdge;
	}

	//if not found return NULL
	if (tempEdge == NULL)
	{
		return NULL;
	}
	else
	{
		return tempEdge;
	}
}

int Graph::WeightIs(string s, string d)
{
	//get Edge Node
	EdgeNode* tempEdge;
	tempEdge = EdgeExists(s, d);

  //else Throws GraphEdgeNotFound
	if(tempEdge == NULL)
	{
		throw GraphEdgeNotFound();
	}
  //if found return
	else
	{
		return tempEdge -> weight;
	}
}

void Graph::ClearMarks()
{
  //create temp var for Vertex
	VertexNode* tempSource = vertices;
  //loop throuh and set all marks to false;
	while(tempSource != NULL)
	{
		tempSource -> mark = false;

		tempSource = tempSource -> nextVertex;
	}
}

void Graph::MarkVertex(string v)
{
  //create temp var for Vertex and get it
	VertexNode* tempVertex = vertices;
	tempVertex = VertexExists(v);

	//if not found throw vertex not found
	if(tempVertex == NULL)
	{
		throw GraphVertexNotFound();
	}
  //if exitsts set mark to true
	else
	{
		tempVertex -> mark = true;
	}

}

bool Graph::IsMarked(string v)
{
  //create temp var for Vertex
	VertexNode* tempVertex = vertices;
	tempVertex = VertexExists(v);

  //if not found throw vertex not found
	if(tempVertex == NULL)
	{
		throw GraphVertexNotFound();
	}
	//if found return temp -> mark
	else
	{
		return tempVertex -> mark;
	}
}

void Graph::GetToVertices(string C, queue<string>& q)
{
	//make tempVertex and tempEdge
	VertexNode* tempVertex = vertices;
	EdgeNode* tempEdge;

	//get vertex
	tempVertex = VertexExists(C);

	//if == NULL throw error
	if(tempVertex == NULL)
	{
		throw GraphVertexNotFound();
	}

	//set edge to vetex
	tempEdge = tempVertex -> edgePtr;

	//else loop through edges and push destination names into queue
	while(tempEdge != NULL)
	{
		q.push(tempEdge -> destination -> vname);

		tempEdge = tempEdge -> nextEdge;
	}
}

void Graph::DepthFirstSearch(string startVertex, string endVertex, queue<string>& path)
{
	//test to see if exists
	if(VertexExists(startVertex) == NULL || VertexExists(endVertex) == NULL)
	{
		throw GraphVertexNotFound();
	}

	//create instance of data type
	stack<string> nodeStack;
	queue<string> nodeQueue;

	//create variables
	bool isFound = false;
	string vertex;
	string item;

	//clears marks and loads first point
	ClearMarks();
	nodeStack.push(startVertex);

	do
	{
		vertex = nodeStack.top();
		nodeStack.pop();
		if (vertex == endVertex)
		{
			path.push(vertex);
			isFound = true;

		}

		else
		{
			if(!IsMarked(vertex))
			{
				MarkVertex(vertex);
				path.push(vertex);
				GetToVertices(vertex, nodeQueue);

				while(!nodeQueue.empty())
				{
					item = nodeQueue.front();
					nodeQueue.pop();
					if(!IsMarked(item))
					{
						nodeStack.push(item);
					}
				}
			}
		}
	} while (!nodeStack.empty() && !isFound);
  if (!isFound)
  {
    while (!path.empty())
    {
      path.pop();
    }
  }
}

void Graph::BreadthFirstSearch(string startVertex, string endVertex, queue<string>& visitedq)
{
  if(VertexExists(startVertex) == NULL || VertexExists(endVertex) == NULL)
  {
    throw GraphVertexNotFound();
  }

  queue<string> NodeQ;
  queue<string> VertexQ;

  bool isFound = false;
  string vertex;
  string item;

  ClearMarks();
  NodeQ.push(startVertex);

  do {
    vertex = NodeQ.front();
      NodeQ.pop();


    if(vertex == endVertex)
    {
      visitedq.push(vertex);
      isFound = true;
    }
    else
    {
      if(!IsMarked(vertex))
      {
        MarkVertex(vertex);
        visitedq.push(vertex);
        GetToVertices(vertex, VertexQ);

        while(!VertexQ.empty())
        {
          item = VertexQ.front();
          VertexQ.pop();
          if(!IsMarked(item))
          {
            NodeQ.push(item);
          }
        }
      }
    }
  } while(!NodeQ.empty() && !isFound);
  if (!isFound)
  {
    while (!visitedq.empty())
    {
      visitedq.pop();
    }
  }
}

Graph::~Graph()
{
	//create temp var for vertex and edges and holders
	VertexNode* holderVertex;
	EdgeNode* holderEdge;

	while(vertices != NULL)
	{
		if(vertices -> edgePtr != NULL)
		{
			while (vertices -> edgePtr != NULL)
			{
				holderEdge = vertices -> edgePtr -> nextEdge;
				delete vertices -> edgePtr;
				vertices -> edgePtr = holderEdge;
			}
		}
		holderVertex = vertices -> nextVertex;
		delete vertices;
		vertices = holderVertex;
	}
}
