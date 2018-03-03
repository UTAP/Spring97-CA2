#!/usr/bin/env python3


from random import randrange, randint


class DAG:
    """Directed Acyclic Graph"""
    def __init__(self, v, e):
        if(e < 0):
            raise ValueError("'e' should be non-negative.")
        if(v < 0):
            raise ValueError("'v' should be non-negative.")
        if e >= v:
            raise ValueError("A DAG with %d vertice(s) could have %d edges at most." % (v, v - 1))

        self.v = v
        self.e = e
        self.edges = []
        self.components = [{i} for i in range(v)]

        while(len(self.edges) < e):
            start = randrange(0, v)
            end = randrange(0, v)
            if (start, end) in self.edges:
                continue
            for component in self.components:
                if start in component:
                    start_component = component
                if end in component:
                    end_component = component
            if start_component == end_component:
                continue
            start_component.update(end_component)
            self.components.remove(end_component)
            self.edges.append((start, end))

    def __repr__(self):
        return str(self.components) + "\n" + str(self.edges)

    def __str__(self):
        return "\n".join(["%d %d" % i for i in self.edges])


def main():
    dag = DAG(1000, 600)
    print("\n".join([
        "%d %d %d" % (dag.v, dag.e, randint(0, dag.v)),
        "\n".join(["%d" % randint(100, 1000) for i in range(dag.v)]),
        "%s" % dag
    ]))


if __name__ == '__main__':
    main()
