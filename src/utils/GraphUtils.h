#ifndef MINIMUM_COST_FLOWS_PROBLEM_GRAPHUTILS_H
#define MINIMUM_COST_FLOWS_PROBLEM_GRAPHUTILS_H

#include <string>
#include "data_structures/graph/Graph.h"

namespace  utils {
    /**
     * Graph's utility function
     */
    class GraphUtils {
        public:
            /**
             * Create graph from json and return it.
             * (See graph.json to see how to format the file)
             *
             * @param file_name name of the file to read
             * @return graph created from the file inputs
             * @throws invalid_argument if the file does not exist
             * @throws invalid_argument if the json is not formatted correctly
             */
            static std::shared_ptr<data_structures::Graph> CreateGraphFromJSON(std::string file_name);

            /**
             * Get the residual graph of the given graph.
             *
             * (see https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/tutorial/)
             *
             * @param graph the graph to get the residual graph from
             * @return the residual graph
             */
            static std::shared_ptr<data_structures::Graph> GetResidualGraph(std::shared_ptr<data_structures::Graph> graph);

            /**
             * Get the optimal graph of the given graph.
             *
             * (see https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/tutorial/)
             *
             * @param graph the graph to get the optimal graph from
             * @return the optimal graph
             */
            static std::shared_ptr<data_structures::Graph> GetOptimalGraph(std::shared_ptr<data_structures::Graph> graph);

            /**
             * Retrieve the path from the node to the source (node with -1 as parent).
             *
             * @param parent
             * @param node
             * @return the path from node to the source node
             */
            static std::shared_ptr<std::vector<int>> RetrievePath(std::shared_ptr<std::vector<int>> parent, int node);

            /**
             * Get the residual capacity of the path in the residual_graph.
             * The residual capacity is the minimum residual capacity of the edges in the path.
             *
             * @param residual_graph the residual_graph
             * @param path the path
             * @return the residual capacity of the path
             */
            static int GetResidualCapacity(std::shared_ptr<data_structures::Graph> residual_graph, std::shared_ptr<std::vector<int>> path);

            /**
             * Send flow in a path of edges of a residual residual_graph.
             *
             * @param residual_graph the residual residual_graph (IT MUST BE A RESIDUAL GRAPH, see the function above)
             * @param path the path of the edge to update
             * @param flow the flow to send
             */
            static void SendFlowInPath(std::shared_ptr<data_structures::Graph> residual_graph, std::shared_ptr<std::vector<int>> path, int flow);
    };
}

#endif //MINIMUM_COST_FLOWS_PROBLEM_GRAPHUTILS_H
