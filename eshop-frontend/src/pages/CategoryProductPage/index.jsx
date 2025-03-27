import React, { useState, useEffect } from 'react';
import { useParams, Link } from 'react-router-dom';
import ApiClient from '../../client/ApiClient';

const CategoryProductPage = () => {
    const { id: categoryId } = useParams();
    const [products, setProducts] = useState([]);
    const [category, setCategory] = useState(null);
    const [loading, setLoading] = useState(false);
    const [error, setError] = useState('');

    useEffect(() => {
        const fetchData = async () => {
            setLoading(true);
            try {
                const [categoryRes, productsRes] = await Promise.all([
                    ApiClient.get(`/categories/${categoryId}`),
                    ApiClient.get(`/categories/${categoryId}/products`)
                ]);
                setCategory(categoryRes.data);
                setProducts(productsRes.data);
            } catch (err) {
                setError('Failed to load data');
                console.error(err);
            } finally {
                setLoading(false);
            }
        };

        fetchData();
    }, [categoryId]);

    if (loading) return <div className="container py-4">Loading...</div>;
    if (error) return <div className="container py-4 alert alert-danger">{error}</div>;
    if (!category) return <div className="container py-4">Category not found</div>;

    return (
        <div className="container py-4">
            <div className="mb-4">
                <h2>{category.name}</h2>
                {category.description && <p>{category.description}</p>}
            </div>

            {products.length === 0 ? (
                <p>No products in this category</p>
            ) : (
                <div className="row">
                    {products.map(product => (
                        <div className="col-md-4 mb-4" key={product.productId}>
                            <div className="card h-100">
                                {product.image && (
                                    <img 
                                        src={product.image} 
                                        alt={product.name}
                                        className="card-img-top"
                                        style={{ height: '180px', objectFit: 'cover' }}
                                    />
                                )}
                                <div className="card-body">
                                    <h5>{product.name}</h5>
                                    <p>{product.description}</p>
                                    <div className="d-flex justify-content-between align-items-center">
                                        <span>${product.price}</span>
                                        <Link 
                                            to={`/products/details/${product.productId}`}
                                            className="btn btn-sm btn-primary"
                                        >
                                            Details
                                        </Link>
                                    </div>
                                </div>
                            </div>
                        </div>
                    ))}
                </div>
            )}

            <Link to="/" className="btn btn-outline-secondary mt-3">
                Back to Categories
            </Link>
        </div>
    );
};

export default CategoryProductPage;