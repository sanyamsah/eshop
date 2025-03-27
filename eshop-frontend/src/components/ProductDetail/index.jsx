import React, { useState, useEffect } from 'react';
import { useParams, Link } from 'react-router-dom';
import ApiClient from '../../client/ApiClient';

const ProductDetail = () => {
    const { id } = useParams();
    const [product, setProduct] = useState(null);
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState(null);

    const getProductDetail = async () => {
        try {
            const response = await ApiClient.get(`/products/${id}`);
            setProduct(response.data);
        } catch (err) {
            setError(err.response?.data?.message || "Failed to load product details");
        } finally {
            setLoading(false);
        }
    };

    useEffect(() => {
        getProductDetail();
    }, [id]);

    if (loading) return (
        <div className="container py-5 text-center">
            <div className="spinner-border text-primary" role="status">
                <span className="visually-hidden">Loading...</span>
            </div>
            <p className="mt-2">Loading product details...</p>
        </div>
    );

    if (error) return (
        <div className="container py-5">
            <div className="alert alert-danger text-center">
                {error}
                <Link to="/products" className="btn btn-link">Back to Products</Link>
            </div>
        </div>
    );

    if (!product) return (
        <div className="container py-5">
            <div className="alert alert-warning text-center">
                Product not found
                <Link to="/products" className="btn btn-link">Back to Products</Link>
            </div>
        </div>
    );

    return (
        <div className="container py-5">
            <div className="row g-4">
                <div className="col-lg-6">
                    <div className="bg-white p-3 rounded shadow-sm">
                        <img 
                            src={product.image} 
                            alt={product.name}
                            className="img-fluid rounded"
                            style={{ maxHeight: '500px', objectFit: 'contain' }}
                        />
                    </div>
                </div>
                <div className="col-lg-6 d-flex flex-column">
                    <div className="bg-white p-4 rounded shadow-sm flex-grow-1">
                        <h1 style={{ color: '#006A71' }}>{product.name}</h1>
                        
                        <span 
                            className="badge mb-3" 
                            style={{ 
                                backgroundColor: '#48A6A7',
                                color: 'white',
                                fontSize: '1rem'
                            }}
                        >
                            {product.category?.name}
                        </span>
                        
                        <p className="lead" style={{ color: '#333' }}>{product.description}</p>
                        
                        <h2 className="my-4" style={{ color: '#006A71' }}>
                            ${product.price}
                        </h2>
                        
                        <button 
                            className="btn btn-lg w-100 mb-3"
                            style={{
                                backgroundColor: '#006A71',
                                color: 'white',
                                border: 'none'
                            }}
                            onMouseEnter={(e) => e.target.style.backgroundColor = '#48A6A7'}
                            onMouseLeave={(e) => e.target.style.backgroundColor = '#006A71'}
                        >
                            Add to Cart
                        </button>
                    </div>

                    <div className="mt-auto pt-3">
                        <Link
                            to="/products"
                            className="btn btn-outline-secondary btn-lg w-100"
                            style={{
                                borderColor: '#006A71',
                                color: '#006A71'
                            }}
                            onMouseEnter={(e) => {
                                e.target.style.backgroundColor = '#F2EFE7';
                            }}
                            onMouseLeave={(e) => {
                                e.target.style.backgroundColor = 'transparent';
                            }}
                        >
                            Back to Products
                        </Link>
                    </div>
                </div>
            </div>
        </div>
    );
};

export default ProductDetail;