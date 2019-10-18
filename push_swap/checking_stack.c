	ft_printf("load from file stack_a:\n");
	stack_print(&stack_a);

	ft_printf("do sa, stack_a:\n");
	sa(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do sa again, stack_a:\n");
	sa(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do pb\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do pb again\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do pb again\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do pb again\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do pb again\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do pa\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);
	ft_printf("do pa again\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do sb, stack_b:\n");
	sb(&stack_a, &stack_b);
	stack_print(&stack_b);

	ft_printf("do pa again\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do sb, stack_b:\n");
	sb(&stack_a, &stack_b);
	stack_print(&stack_b);

	ft_printf("do ra, stack_a:\n");
	ra(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do ra, stack_a:\n");
	ra(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do ra, stack_a:\n");
	ra(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do pb\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do ra, stack_a:\n");
	ra(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do pa\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do rra, stack_a:\n");
	rra(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do pa\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do rra, stack_a:\n");
	rra(&stack_a, &stack_b);
	stack_print(&stack_a);
