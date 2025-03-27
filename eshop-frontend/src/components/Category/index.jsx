import { Link } from "react-router-dom";

const Category = (props) => {
    const { id, name, image, description } = props.data;
    
    return (
        <div className="col-sm-6 col-md-4 col-lg-3 mb-4">
            <div 
                className="card h-100" 
                style={{ 
                    backgroundColor: '#F2EFE7',
                    border: 'none',
                    boxShadow: '0 4px 8px rgba(0, 0, 0, 0.1)',
                    transition: 'transform 0.3s ease, box-shadow 0.3s ease'
                }}
            >
                <img 
                    src={image} 
                    alt={name} 
                    className="card-img-top p-3" 
                    style={{
                        objectFit: 'cover',
                        height: '200px',
                        borderRadius: '8px'
                    }}
                />
                <div className="card-body d-flex flex-column">
                    <h5 className="card-title" style={{ color: '#006A71' }}>{name}</h5>
                    <p className="card-text" style={{ color: '#333' }}>{description}</p>
                    <Link 
                        to={`/categories/${id}/products`} 
                        className="btn mt-auto align-self-stretch"
                        style={{
                            backgroundColor: '#006A71',
                            color: 'white',
                            border: 'none',
                            borderRadius: '4px',
                            transition: 'background-color 0.3s ease'
                        }}
                        onMouseEnter={(e) => e.target.style.backgroundColor = '#48A6A7'}
                        onMouseLeave={(e) => e.target.style.backgroundColor = '#006A71'}
                    >
                        View Products
                    </Link>
                </div>
            </div>
        </div>
    );
}

export default Category;