import sys
from itertools import combinations


input_func = sys.stdin.readline
if __name__ == '__main__':
    N = int(*map(int, input_func().split()))
    mp, mf, ms, mv = map(int, input_func().split())
    ingredients = {idx + 1 : tuple(map(int, input_func().split())) for idx in range(N)}

    min_cost, min_ingredient = 1e9, []
    for num in range(1, len(ingredients)+1):
        for comb in combinations(ingredients.keys(), num):
            ingredient_sample = [ingredients[comb[idx]] for idx in range(len(comb))]
            ingredient_sample_transpose = list(map(list, zip(*ingredient_sample)))

            if mp <= sum(ingredient_sample_transpose[0]) and mf <= sum(ingredient_sample_transpose[1])  \
                and ms <= sum(ingredient_sample_transpose[2]) and mv <= sum(ingredient_sample_transpose[3]):
                current_cost = sum(ingredient_sample_transpose[4])
                if min_cost > current_cost:
                    min_cost = current_cost
                    min_ingredient = [comb]
                elif min_cost == current_cost:
                    min_ingredient.append(comb)


    if min_cost != 1e9:
        print(min_cost)
        print(' '.join(map(str, sorted(min_ingredient)[0])))
    else:
        print('-1')
